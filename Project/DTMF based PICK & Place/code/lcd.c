#include <reg51.h>
#include "lcd.h"
#include "delay.h"

void lcdcmd(char a)
{
	LCDport = a;
	RS = 0;
	RW = 0;
	EN = 1;
	delay(10);
	EN = 0;
}

void lcddata(char a)
{
	LCDport = a;
	RS = 1;
	RW = 0;
	EN = 1;
	delay(10);
	EN = 0;	
}

void lcdbegin()
{
	lcdcmd(0x38);
	delay(1);
	lcdcmd(0x0C);
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

void lcdsetCursor(char col,char row)
{
	if(row == 0)
	{
		lcdcmd(0x80 + col);
	}
	else
	{
		lcdcmd(0xC0 + col);
	}
}

void lcdclear()
{
	lcdcmd(0x01);
	delay(1);
}

