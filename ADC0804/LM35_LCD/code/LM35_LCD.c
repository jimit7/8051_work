//************************************//

//NAME:   Jignesh Patoliya.
//TITLE:  READ THE VALUE OF LM35 TEMPERATURE SENSOR AND DISPLAY ON LED
//DATE:   07/03/2015

//***********************************//

//***********START****************//

#include<reg51.h>
#include "adc804.h"
#include "delay.h"
#include "lcd.h"

#define LED P1 

unsigned char Dout;

//************MAIN PROGRAM***********//

void main()
{	  	
	adcInit();
	lcdbegin();
	lcdclear();
	lcdsetCursor(0,0);
	lcdprint("Temp. = ");
	while(1)
	{
		Dout = (analogRead()) * 2;
		lcdsetCursor(8,0);
		lcdwrite(Dout);
		delay(1000);
	}

}

//**************STOP**************//

	