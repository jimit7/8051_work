//************************************//
//Reverse Current Protection

//***********************************//

//***********START****************//

#include<reg51.h>
#include "adc804.h"
#include "delay.h"
#include "lcd.h"


void setvalue(void);

sbit inc = P0^0;
sbit dec = P0^1;
sbit OK = P0^2;
sbit buzzer = P0^3;
sbit LED = P0^4;
sbit RELAY = P0^5;

unsigned char Dout;
unsigned int g = 25 ;


//************MAIN PROGRAM***********//

void main()
{	  	
	int i;
	RELAY = 0;
    buzzer = 0;
	LED = 0;
	adcInit();
	lcdbegin();
	lcdclear();
	setvalue();
	lcdclear();
//	lcdprint("CTValue : ");
	RELAY = 0;
	while(1)
	{
		Dout = analogRead();
	//	lcdsetCursor(10,0);
	//	lcdwrite(Dout);
		
		if(Dout > g)
		{
		 //   lcdclear();
			lcdsetCursor(0,0);
			lcdprint("Reverse Power");
			for(i=0;i<10;i++)
			{
				buzzer = 1;
				LED = 1;
				delay(500);
				
				buzzer = 0;
				LED = 0;
				delay(500); 
			}
			RELAY = 1;
		}

		else
		{
			RELAY = 0;
			delay(100);
		//	lcdclear();
			lcdsetCursor(0,0);
			lcdprint("Forward Power");
		}

		delay(5000);

	
	}

}

//**************STOP**************//

void setvalue()
{
	inc = 1;
	dec = 1;
	OK = 1;

	lcdsetCursor(0,0);
	delay(1);
	lcdprint("Set limit:");
	while(1)
	{
		if(inc == 0)
		{
			g = g+1;
			delay(200);
		}
		if(dec == 0)
		{
			g = g-1;
			delay(200);
		}
		if(OK == 0)
		{
			goto start;
		}

		lcdsetCursor(12,0);
		lcdwrite(g);
		
	}
	
start:
	lcdclear();
	lcdprint("Welcome");

}	