//NAME:   
//TITLE:  LED ON-OFF USING EXTERNAL INTERRUPT.
//DATE:   4/1/2014

//***********************************//

//***********START****************//

#include<reg51.h>
sbit LED = P1^7;
sbit wave = P3^2;
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

//***********EXTERNAL INTERRUPT 0****************//

void Ex0() interrupt 0
{	
	LED = wave;
}


//***********MAIN PROGRAM****************//

void main()
{
	 IE = 0x89;
	 TMOD = 0x11;
	 TH1 = 0xFC;
	 TL1 = 0x66;
	 TR1 = 1;
	 while(1);
}

//***********STOP****************//













