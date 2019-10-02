//************************************//

//NAME:   Jignesh Patoliya.
//TITLE:  READ THE VALUE OF LM35 TEMPERATURE SENSOR AND DISPLAY ON LED
//DATE:   07/03/2015

//***********************************//

//***********START****************//

#include<reg51.h>
#include "adc804.h"
#define LED P1 

unsigned char Dout;

//************MAIN PROGRAM***********//

void main()
{	  	
	adcInit();
	while(1)
	{
		Dout = analogRead();
		LED = Dout;
		delay(10)
	}

}

//**************STOP**************//

	