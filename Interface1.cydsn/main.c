#include "project.h"
#include <stdlib.h>
#include <stdio.h>

// Definitions
#define SCD30_I2C_ADDRESS 0x61
#define VREF 5.0
#define ADC_MAX_VALUE 4095
#define VTHRESHOLD (VREF * 0.63) // 63% charged up of capacitor
#define R1 1000.0 // 1k ohm resistor
#define R2 10000.0 // 10k ohm resistor
#define TIMER_RESOLUTION 2.0e-6
#define CORRECTION_FACTOR 1.0e3

// Function prototypes
void I2C_Write(uint8_t *data, uint8_t length);
void I2C_Read(uint8_t *data, uint8_t length);
void read_sensor_data();
void read_capacitance();
// Global variables
char string_1[100];
double capMeasureArray[5];
uint8_t buffer[18]; // Buffer for 18 bytes of data
uint16 adcResult;

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



int main(void) {
    CyGlobalIntEnable;
    I2C_1_Start();
    UART_1_Start();
    ADC_SAR_1_Start();
    Timer_1_Start();
    Counter_1_Start();

    // Start continuous measurement with 0x0010 command and pressure 0x0000
    uint8_t startCmd[5] = {0x00, 0x10, 0x00, 0x00, 0x81}; // 0x81 is CRC for 0x0000
    I2C_Write(startCmd, sizeof(startCmd));
    CyDelay(1000); // Allow sensor initialization
    UART_1_PutString("Starting sensor reading...\n");

    for(;;) 
    {
        // Command to read data (0x0300)
        uint8_t readCmd[2] = {0x03, 0x00};
        I2C_Write(readCmd, sizeof(readCmd));
        CyDelay(300); // Wait for command processing
        read_sensor_data();
        CyDelay(1000); // Match measurement interval
        read_capacitance();
    }
}