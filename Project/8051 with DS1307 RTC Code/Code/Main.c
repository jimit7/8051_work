/*  Name     : main.c
 
 *  Revision : None
 */
#include "Includes.h"

unsigned char eepromRead(unsigned char);



void Write_Byte_To_eeprom(unsigned char Address1, unsigned char DataByte1)
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
unsigned char eepromRead(unsigned char Address11)
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




			 
	



	
	
 



// Main function
void main()
{	

	unsigned char i,j;
	InitI2C();	// Initialize i2c pins	
	lcdbegin();
	delay(10);
//	lcdclear();
//	lcd
	lcdprint("Value =");
	Write_Byte_To_eeprom(0x00,06);
    i = eepromRead(0x00);
	lcdsetCursor(8,0);
	lcdwrite(i);
	lcdsetCursor(0,1);
	j = get_key;
	lcdwrite(j);
	while(1);
//	{
//	
//	Write_Byte_To_eeprom(0x01,m1);
//	Write_Byte_To_eeprom(0x02,h2);
//	Write_Byte_To_eeprom(0x03,m2);
//	}


 
 	

}