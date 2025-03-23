#include "project.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

// Definitions
#define SCD30_I2C_ADDRESS 0x61
#define R1 1000.0 // 1k ohm resistor
#define R2 10000.0 // 10k ohm resistor
#define R3 22000.0 //22k ohm resistor
#define VREF 4.9
#define ADC_MAX_VALUE 4095
// JS6670 nominal parameters (from datasheet/specs)
#define R0          9983.0      // Nominal resistance at 25°C in Ohms
#define T0          298.15      // Nominal temperature in Kelvin (25°C)
#define BETA        3870.0     // Beta parameter in Kelvin

// Function prototypes
void I2C_Write(uint8_t *data, uint8_t length);
void I2C_Read(uint8_t *data, uint8_t length);
void read_sensor_data();
void read_capacitance();
void heater();
void read_temperature();
// Global variables
char string_1[100];
uint8_t buffer[18]; // Buffer for 18 bytes of data
uint16 adcResult, heaterDutyCycle;
uint8 status;
float  voltage;
float  R_thermistor;
float  temperatureK, temperatureC;
int    tempCeil;
// Temperature control (PID)
float Kp = 10.0f;
float Ki = 5.0f;
float Kd = 1.0f;
float dt = 1.0f; // Matches sampling period
float setpoint = 60.0f;
float error, derivative, integral, prevErr;

void I2C_Write(uint8_t *data, uint8_t length) {
    I2C_1_MasterWriteBuf(SCD30_I2C_ADDRESS, data, length, I2C_1_MODE_COMPLETE_XFER);
    while(I2C_1_MasterStatus() & I2C_1_MSTAT_XFER_INP);
}

void I2C_Read(uint8_t *data, uint8_t length) {
    I2C_1_MasterReadBuf(SCD30_I2C_ADDRESS, data, length, I2C_1_MODE_COMPLETE_XFER);
    while(I2C_1_MasterStatus() & I2C_1_MSTAT_XFER_INP);
}

void read_sensor_data()
{
    // Ensure buffer is updated before reading values
    I2C_Read(buffer, sizeof(buffer));  

    uint32_t co2BytesUpper = (buffer[0] << 8) | buffer[1];
    uint32_t co2BytesLower = (buffer[3] << 8) | buffer[4];
    uint32_t co2Bytes = ((uint32_t)co2BytesUpper << 16) | co2BytesLower;
    int co2Concentration = (int)*(float*)&co2Bytes;
    
    uint32_t tempBytesUpper = (buffer[6] << 8) | buffer[7];
    uint32_t tempBytesLower = (buffer[9] << 8) | buffer[10];
    uint32_t tempBytes = ((uint32_t)tempBytesUpper << 16) | tempBytesLower;
    int temperature = (int)*(float*)&tempBytes;
    
    uint32_t rhBytesUpper = (buffer[12] << 8) | buffer[13];
    uint32_t rhBytesLower = (buffer[15] << 8) | buffer[16];
    uint32_t rhBytes = ((uint32_t)rhBytesUpper << 16) | rhBytesLower;
    int rh = (int)*(float*)&rhBytes;
    
//    float capacitance = read_capacitance();
    
    if (co2Concentration != 0 && temperature != 0 && rh != 0)
    {
        sprintf(string_1, "CO2: %d ppm, Temperature: %d degrees, Relative Humidity: %d%%\n", co2Concentration, temperature, rh);
        UART_1_PutString(string_1);  // Send output via UART
    }
}

void read_capacitance()
{
    // 1) Clear the counter
    Counter_1_WriteCounter(0);  
    
    // 2) Wait a known time (e.g., 1 second)
    CyDelay(1000);  // 1000 ms
    
    // 3) Read how many pulses arrived in that time
    uint32_t pulseCount = Counter_1_ReadCounter();
    // Calculate the capacitance connected
    double capMeasured = 1.44/((R1 + 2*R2)*pulseCount) * 1.0e9;
    // 4) That count is your frequency in Hz (since you waited 1 second)
    sprintf(string_1,"Frequency = %lu Hz, Capacitance: %d nF\n", (unsigned long)pulseCount, (int)capMeasured);
    UART_1_PutString(string_1);
}

// Bang-bang on/off controller test implementation
void heater()
{
    // Start the PWM module once
    PWM_1_Start();
    // Set the heater direction: only one side is activated for heat flow.
    Heater_IN1_Write(1);
    Heater_IN2_Write(0);
    
    // Set the duty cycle to 100% (for full power)
    heaterDutyCycle = 255;
    PWM_1_WriteCompare(heaterDutyCycle);
    
    // Enable the heater channel by setting the ENA pin high.
    Heater_ENA_Write(1);
    UART_1_PutString("Begin heating...\n");
    
    // Loop until the temperature exceeds 60°C
    // May need extra condition such that when capacitance of IDE goes down below threshold, heater stops
    while (tempCeil <= setpoint)
    {
        // Read temperature and update the global variable tempCeil
        read_temperature();
        
        error = setpoint - tempCeil;
        integral += error*dt;
        derivative = (error - prevErr)/dt;
        prevErr = error;
        
        float output = error*Kp + integral*Ki + derivative*Kd;
        heaterDutyCycle = (int)output;
        // Clamp pwm duty cycle
        if (heaterDutyCycle > 255)
        {
            heaterDutyCycle = 255;
        }
        else if (heaterDutyCycle < 0)
        {
            heaterDutyCycle = 0;
        }
        
        // Print out controls params
        sprintf(string_1, "Set: %d, Temp: %d, Err: %d, PWM: %d\r\n", (int)setpoint, tempCeil, (int)ceil(error), heaterDutyCycle);
        UART_1_PutString(string_1);
    }
    
    // Turn off the heater once 60°C is reached
    Heater_ENA_Write(0);
    PWM_1_Stop();
    
    // Set the control pins to low
    Heater_IN1_Write(0);
    Heater_IN2_Write(0);
    UART_1_PutString("Heating stopped.\n");
}


void read_temperature()
{
    
        /* Kick off a single ADC conversion */
        ADC_SAR_1_StartConvert();

        /* Wait until the conversion completes */
        do
        {
            status = ADC_SAR_1_IsEndConversion(ADC_SAR_1_RETURN_STATUS);
        }
        while (status == 0);

        /* Get the ADC raw count */
        adcResult = ADC_SAR_1_GetResult16();

        /* Convert raw count to a voltage in [0..VREF] */
        voltage = ADC_SAR_1_CountsTo_Volts(adcResult);

        R_thermistor = R3*(VREF - voltage) / voltage;

        /* Compute temperature using Beta equation if R_thermistor > 0 */
        if (R_thermistor > 0.0f)
        {
            /* T(K) = BETA / (ln(R/R0) + (BETA/T0)) */
            temperatureK = BETA / (logf(R_thermistor / R0) + (BETA / T0));
            temperatureC = temperatureK - 273.15f;
        }
        else
        {
            temperatureC = -999.0f;  // sentinel for error
        }

        /* Round up the temperature to next integer */
        tempCeil = (int)ceilf(temperatureC);

        /* Print integer result via UART */
        sprintf(string_1, "Current temperature: %d degrees Celsius\r\n", tempCeil);
        UART_1_PutString(string_1);

        /* Delay 1 second before next reading */
        CyDelay(1000u);
}



int main(void) {
    CyGlobalIntEnable;
    I2C_1_Start();
    UART_1_Start();
    Counter_1_Start();
    //PWM_1_Start();
    ADC_SAR_1_Start();

    // Start continuous measurement with 0x0010 command and pressure 0x0000
    uint8_t startCmd[5] = {0x00, 0x10, 0x00, 0x00, 0x81}; // 0x81 is CRC for 0x0000
    I2C_Write(startCmd, sizeof(startCmd));
    CyDelay(1000); // Allow sensor initialization
    UART_1_PutString("Starting sensor reading...\n");
    heater();
    for(;;) 
    {
//        // Command to read data (0x0300)
//        uint8_t readCmd[2] = {0x03, 0x00};
//        I2C_Write(readCmd, sizeof(readCmd));
//        CyDelay(300); // Wait for command processing
//        read_sensor_data();
//        CyDelay(1000); // Match measurement interval
//        read_capacitance();
//        
//        // Temperature sensor
//        read_temperature();
    }
}