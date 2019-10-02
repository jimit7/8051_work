//************************************//

//NAME:
//TITLE:  GENERATE SQUARE WAVE OF 1s PULSE ON PIN P1.0 AND PIN P1.1 USING TIMER 0 AND TIMER2.
//DATE:   3/1/2014

//***********************************//

//***********START****************//

#include<reg51.h>
sbit wave1 = P1^0;
sbit wave2 = P1^1;
int count1, count2;

//***********INTERRUPT FOR TIMER 1****************//

void timer1() interrupt 3
{
	count2++;
	if(count2 == 1000)
	{
		wave2 = ~wave2;
		count2 = 0;	
	}
	
	TH1 = 0xFC;
	TL1 = 0x66;
}

//***********INTERRUPT FOR TIMER 0****************//

void timer0() interrupt 1
{
	count1++;
	if(count1 == 1000)
	{
		wave1 = ~wave1;
		count1 = 0;	
	}
	
	TH0 = 0xFC;
	TL0 = 0x66;
}

//***********MAIN PROGRAM****************//

void main()
{
	 IE = 0x8A;
	 TMOD = 0x11;
	 TH0 = 0xFC;	//value for 1ms pulse for timer0 interrupt;
	 TL0 = 0x66;
	 TH1 = 0xFC;	//value for 1ms pulse for timer0 interrupt;
	 TL1 = 0x66;
	 TR0 = 1;		//timer0 start;
	 TR1 = 1;		//timer1 start;
	 while(1);
}

//***********STOP****************//













