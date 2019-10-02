//************************************//

//TITLE:  GENERATE SQUARE WAVE OF 1ms PULSE ON PIN P1.0 USING TIMER 0.
//DATE:   3/1/2014

//***********************************//

//***********START****************//

#include<reg51.h>
sbit wave = P1^0;

//***********INTERRUPT FOR TIMER 0****************//

void timer0() interrupt 1
{
	wave = ~wave;
	TH0 = 0xFC;
	TL0 = 0x66;
}

//***********MAIN PROGRAM****************//

void main()
{
	 IE = 0x82;
	 TMOD = 0x11;
	 TH0 = 0xFC;
	 TL0 = 0x66;
	 TR0 = 1;
	 while(1);
}


//***********STOP****************//












