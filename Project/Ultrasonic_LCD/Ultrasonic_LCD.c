#include <reg51.h>
#include <intrins.h>
#include "delay.h"
#include "lcd.h"


unsigned int getDistance();

sbit tri = P2^0;
sbit echo = P2^1;



unsigned int count = 0,cm = 0;


/*************** Main function **********************/

void main()
{
   lcdbegin();
   lcdclear();
   lcdprint("DISTANCE:-");
   delay(1000);
   while(1)
   {
   		cm = getDistance();
		lcdsetCursor(10,0);
	    lcdwrite(cm);
		lcdsetCursor(13,0);
		lcdprint("cms");
		delay(600);
		count = 0;
	}		
   
   

}

/********** get Distance from Ultrasonic sensor **********/

unsigned int getDistance()
{
	tri = 0;
   echo = 1;

   TMOD = 0x21;
   TH1 = 209;
   TL1 = 209;

   	tri = 0;
	_nop_ ();
	while(1)
	{
		tri = 1;
		_nop_ ();
		_nop_ ();
		_nop_ ();
		_nop_ ();
		_nop_ ();
		_nop_ ();
		_nop_ ();
		_nop_ ();
		_nop_ ();
		_nop_ ();
		tri = 0;

		echo = 1;
		while(echo == 0);
again:
		TR1 = 1;
		while(TF1 == 0);
		TR1 = 0;
		TF1 = 0;
		count++;
		if(echo == 1)
		{
			goto again;
		}

		else
		{
			return count;
		}
 }
}