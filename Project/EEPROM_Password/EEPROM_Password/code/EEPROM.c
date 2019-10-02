#include<reg51.h>
#include "delay.h"
#include "I2C.h"


void EEPROMWrite(unsigned char Address1, unsigned char DataByte1)
{
	I2C_Start();										// Start i2c communication

	// Send i2c address of DS1307 with write command
	while(I2C_Write_Byte(Device_Address_EEPROM + 0) == 1)// Wait until device is free
	{	I2C_Start();	}		

	I2C_Write_Byte(Address1);							// Write Address byte
	I2C_Write_Byte(DataByte1);							// Write data byte
	I2C_Stop();											// Stop i2c communication
}



// Function Purpose: Read_Byte_From_DS1307_RTC reads a single byte from given address
// Address can have any value fromm 0 to 0xFF.
unsigned char EEPROMRead(unsigned char Address11)
{
	unsigned char  Byte = 0;								// Variable to store Received byte

	I2C_Start();										// Start i2c communication

	// Send i2c address of DS1307 with write command
	while(I2C_Write_Byte(Device_Address_EEPROM + 0) == 1)// Wait until device is free
	{	I2C_Start();	}		

	I2C_Write_Byte(Address11);							// Write Address byte
	I2C_ReStart();										// Restart i2c

	// Send i2c address of DS1307 RTC with read command	
	I2C_Write_Byte(Device_Address_EEPROM + 1);		

	Byte = I2C_Read_Byte();								// Read byte from EEPROM

	// Make SCK low, so that slave can stop driving SDA pin
	// Send a NACK to indiacate single byte read is complete
	I2C_Send_NACK();

	// Send start bit and then stop bit to stop transmission
	Set_SDA_Low;				// Make SDA Low
	__delay_us(HalfBitDelay);	// Half bit delay
	Set_SDA_High;				// Make SDA high
	__delay_us(HalfBitDelay);	// Half bit delay

	return Byte;				// Return the byte received from 24LC64 EEPROM
}