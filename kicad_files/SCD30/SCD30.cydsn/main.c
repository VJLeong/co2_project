#include "project.h"
#include <string.h>
#include <stdio.h>

#define SCD30_I2C_ADDRESS 0x61  // Default SCD30 I2C address

uint8_t buffer[18];
char string_1[50] = "\0";

// Function to send a 16-bit command over I2C
void I2C_Write(uint16_t cmd) {
    uint8_t data[2] = { (uint8_t)(cmd >> 8), (uint8_t)(cmd & 0xFF) };
    I2C_1_MasterWriteBuf(SCD30_I2C_ADDRESS, data, 2, I2C_1_MODE_COMPLETE_XFER);
    while(I2C_1_MasterStatus() & I2C_1_MSTAT_XFER_INP);
}

// Function to check if the sensor has data ready
uint8_t I2C_ReadDataReady() {
    // The correct command for "read data ready" is 0x02 0x02
    uint8_t cmd[2] = {0x02, 0x02};
    uint8_t resp[3];

    I2C_1_MasterWriteBuf(SCD30_I2C_ADDRESS, cmd, 2, I2C_1_MODE_COMPLETE_XFER);
    while(I2C_1_MasterStatus() & I2C_1_MSTAT_XFER_INP);

    I2C_1_MasterReadBuf(SCD30_I2C_ADDRESS, resp, 3, I2C_1_MODE_COMPLETE_XFER);
    while(I2C_1_MasterStatus() & I2C_1_MSTAT_XFER_INP);

    // The sensor returns a 16-bit value; here we simply check the second byte.
    return resp[1];  
}

// Function to read measurement data (18 bytes) from the sensor
void I2C_ReadMeasurements() {
    uint8_t cmd[2] = {0x03, 0x00};  // Read measurement command
    I2C_1_MasterWriteBuf(SCD30_I2C_ADDRESS, cmd, 2, I2C_1_MODE_COMPLETE_XFER);
    while(I2C_1_MasterStatus() & I2C_1_MSTAT_XFER_INP);

    I2C_1_MasterReadBuf(SCD30_I2C_ADDRESS, buffer, 18, I2C_1_MODE_COMPLETE_XFER);
    while(I2C_1_MasterStatus() & I2C_1_MSTAT_XFER_INP);
}

// Converts 5 bytes (2 data bytes, 1 CRC, then 2 data bytes) into a float
// Assumes that the CRC byte (at index 2) is skipped.
float bytes_to_float(uint8_t *bytes) {
    uint32_t raw = ((uint32_t)bytes[0] << 24) |
                   ((uint32_t)bytes[1] << 16) |
                   ((uint32_t)bytes[3] << 8)  |
                   ((uint32_t)bytes[4]);
    float value;
    memcpy(&value, &raw, sizeof(float));
    return value;
}

int main(void)
{
    CyGlobalIntEnable;  // Enable global interrupts
    I2C_1_Start();      // Start I2C component
    UART_1_Start();     // Start UART for debugging

    UART_1_PutString("Scanning I2C...\r\n");

    uint8_t status = I2C_1_MasterSendStart(SCD30_I2C_ADDRESS, I2C_1_WRITE_XFER_MODE);
    
    if(status == I2C_1_MSTR_NO_ERROR)
    {
        UART_1_PutString("SCD30 found at address 0x61!\r\n");
        I2C_1_MasterSendStop();
    }
    else
    {
        UART_1_PutString("No response from SCD30!\r\n");
    }
    
    // Start continuous measurement (0x0010). 
    // Optionally, you can send ambient pressure as a 16-bit value (set to 0 if not used).
    I2C_Write(0x0010);

    UART_1_PutString("Give the sensor some time to complete its first measurement\r\n");
    CyDelay(3000);
    UART_1_PutString("Ready to output values\r\n");
    
    for(;;)
    {
        // Check if new data is ready (returns non-zero when ready)
        if (I2C_ReadDataReady())
        {
            I2C_ReadMeasurements();

            // Each measurement is 5 bytes:
            // - CO2: indices 0-4 (skip index 2)
            // - Temperature: indices 6-10 (skip index 8)
            // - Humidity: indices 12-16 (skip index 14)
            float co2 = bytes_to_float(&buffer[0]);
            float temp = bytes_to_float(&buffer[6]);
            float humidity = bytes_to_float(&buffer[12]);

            sprintf(string_1, "CO2: %.2f ppm\r\n", co2);
            UART_1_PutString(string_1);
        }
        CyDelay(2000);  // Wait 2 seconds before next check
    }
}
