#include <reg51.h>
#include "lcd.h"
#include "delay.h"

void lcdcmd(char a)
{
	LCDport &= 0x0F;
	LCDport |= (a & 0xF0);
	RS = 0;
	RW = 0;
	EN = 1;
	delay(10);
	EN = 0;

	LCDport &= 0x0F;
	LCDport |= ((a << 4) & 0xF0);
	RS = 0;
	RW = 0;
	EN = 1;
	delay(10);
	EN = 0;
}

void lcddata(char b)
{
	LCDport &= 0x0F;
	LCDport |= (b & 0xF0);
	RS = 1;
	RW = 0;
	EN = 1;
	delay(10);
	EN = 0;

	LCDport &= 0x0F;
	LCDport |= ((b << 4) & 0xF0);
	RS = 1;
	RW = 0;
	EN = 1;
	delay(10);
	EN = 0;
}

void lcdbegin()
{
	lcdcmd(0x02);
	delay(1);
	lcdcmd(0x28);
	delay(1);
	lcdcmd(0x0e);
	delay(1);
	lcdcmd(0x01);
	delay(1);
	lcdcmd(0x06);
	delay(1);
	lcdcmd(0x80);
	delay(1);
}

void lcdprint(char *buffer)
{
	int i = 0;
	while(buffer[i] != '\0')
	{
		lcddata(buffer[i]);
		i++;
	}
}