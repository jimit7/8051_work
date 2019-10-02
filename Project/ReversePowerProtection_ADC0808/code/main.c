#include <reg51.h>
#include "delay.h"
#include "ADC0808.h"
#include "lcd.h"

void setvalue(void);

sbit inc = P3^2;
sbit dec = P3^3;
sbit OK = P3^4;
sbit buzzer = P3^1;
sbit RELAY = P3^0;

unsigned int g = 25 ;

void main()
{
  unsigned char CTValue;
  lcdbegin();
  ADCbegin();
  lcdclear();
  setvalue();

  while(1)
  {
  	lcdsetCursor(0,0);
 	CTValue = analogRead(A1);
 	lcdprint("CTValue:-");
  	lcdwrite(CTValue);
	
	if(CTValue > g)
	{
		RELAY = 0;
		buzzer = 1;
		delay(500);
		buzzer = 0;
		delay(500);
	}

	else
	{
		RELAY = 1;
	}

	delay(1000);
  }

}

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