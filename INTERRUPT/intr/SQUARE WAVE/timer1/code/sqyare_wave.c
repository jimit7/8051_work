//NAME:   
//TITLE:  GENERATE SQUARE WAVE OF 1s PULSE ON PIN P1.0 USING TIMER 1.
//DATE:   3/1/2014

//***********************************//

//***********START****************//

#include<reg51.h>
sbit wave = P1^0;
int count;

//***********INTERRUPT FOR TIMER 1****************//

void timer1() interrupt 3
{
	count++;
	if(count == 1000)
	{
		wave = ~wave;
		count = 0;	
	}
	
	TH1 = 0xFC;
	TL1 = 0x66;
}

//***********MAIN PROGRAM****************//

void main()
{
	 IE = 0x88;
	 TMOD = 0x11;
	 TH1 = 0xFC;
	 TL1 = 0x66;
	 TR1 = 1;
	 while(1);
}

//***********STOP****************//













