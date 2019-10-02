#include <reg51.h>
#include "delay.h"

sbit  Left  =  P1^0;
sbit Right =  P1^1;

sbit Light = P2^0;
sbit Fan   = P2^1;

int a = 0;
int b =0;

void main()
{
	P1 = 0xFF;
	P2 = 0x00;

	while(1)
	{
		if(Left == 0)
		{
			if(a == 0)
			{
				Light = 1;
				delay(1000);
				a = 1;
			}
			
			else if(a == 1)
			{
				Light = 0;
				delay(1000);
				a = 0;
			}
		

		}	

		if(Right == 0)
		{
			if(b == 0)
			{
				Fan = 1;
				delay(1000);
				b = 1;
			}
			
			else if(b == 1)
			{
				Fan = 0;
				delay(1000);
				b = 0;
			}
		

		}
	
	}	
}

