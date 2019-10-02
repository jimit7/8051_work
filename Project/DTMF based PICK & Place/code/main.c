#include <reg51.h>
#include "delay.h"
#include "lcd.h"
#define dataPort P1

sbit MP1 = P2^0;
sbit MN1 = P2^1;

sbit MP2 = P3^2;
sbit MN2 = P3^3;

sbit MP3 = P2^4;
sbit MN3 = P2^5;

sbit MP4 = P2^6;
sbit MN4 = P2^7;

void main()
{
	dataPort = 0xFF;
	lcdbegin();
	lcdclear();
	lcdsetCursor(0,0);
	lcdprint("Welcome");

	while(1)
	{
		dataPort &= 0x0F;

		switch(dataPort)
		{
			case 2:
				
			    lcdsetCursor(0,0);
				lcdprint("Forward            ");

				MP1 = 1;
				MN1 = 0;

				MP2 = 1;
				MN2 = 0;

				MP3 = 0;
				MN3 = 0;

				MP4 = 0;
				MN4 = 0;

				delay(100);
				break;
			
			case 8:
				
				lcdsetCursor(0,0);
				lcdprint("Reverse         ");

				MP1 = 0;
				MN1 = 1;

				MP2 = 0;
				MN2 = 1;

				MP3 = 0;
				MN3 = 0;

				MP4 = 0;
				MN4 = 0;
				delay(100);
				break;

			case 1:

				lcdsetCursor(0,0);
				lcdprint("Pick             ");
								
				MP1 = 0;
				MN1 = 0;

				MP2 = 0;
				MN2 = 0;

				MP3 = 0;
				MN3 = 1;

				MP4 = 0;
				MN4 = 0;
				delay(100);
				break;

			case 3:

				lcdsetCursor(0,0);
				lcdprint("Place           ");				
				MP1 = 0;
				MN1 = 0;

				MP2 = 0;
				MN2 = 0;

				MP3 = 1;
				MN3 = 0;

				MP4 = 0;
				MN4 = 0;
				delay(100);
				break;

		   case 4:
		   		
				lcdsetCursor(0,0);
				lcdprint("left            ");

				MP1 = 1;
				MN1 = 0;

				MP2 = 0;
				MN2 = 0;

				MP3 = 0;
				MN3 = 0;

				MP4 = 0;
				MN4 = 0;

				delay(100);
				break;
		   
		   case 6:
		   		lcdsetCursor(0,0);
				lcdprint("Right            ");
				
				MP1 = 0;
				MN1 = 0;

				MP2 = 1;
				MN2 = 0;

				MP3 = 0;
				MN3 = 0;

				MP4 = 0;
				MN4 = 0;

				delay(100);
				break;

		   case 7:
				
				lcdsetCursor(0,0);
				lcdprint("UP           ");
				MP1 = 0;
				MN1 = 0;

				MP2 = 0;
				MN2 = 0;

				MP3 = 0;
				MN3 = 0;

				MP4 = 1;
				MN4 = 0;
				delay(100);
				break;
		   
		   case 9:
		   	
				lcdsetCursor(0,0);
				lcdprint("Down           ");	
				MP1 = 0;
				MN1 = 0;

				MP2 = 0;
				MN2 = 0;

				MP3 = 0;
				MN3 = 0;

				MP4 = 0;
				MN4 = 1;
				delay(100);
				break;
		  default:
		  		lcdsetCursor(0,0);
				lcdprint("Stop         ");

		  		MP1 = 0;
				MN1 = 0;

				MP2 = 0;
				MN2 = 0;

				MP3 = 0;
				MN3 = 0;

				MP4 = 0;
				MN4 = 0;
				P2 = 0x00;

		        break;       

		}
		delay(50);
		MP1 = 0;
		MN1 = 0;

		MP2 = 0;
		MN2 = 0;
		
		MP3 = 0;
		MN3 = 0;

		MP4 = 0;
		MN4 = 0;
	}
}