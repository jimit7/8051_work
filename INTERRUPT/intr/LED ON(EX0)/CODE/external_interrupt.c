//NAME:
//TITLE:  LED ON-OFF USING EXTERNAL INTERRUPT.
//DATE:   4/1/2014

//***********************************//

//***********START****************//

#include<reg51.h>
sbit LED = P1^0;


//***********EXTERNAL INTERRUPT 0****************//

void Ex0() interrupt 0
{	
	LED = 0;
}

//***********MAIN PROGRAM****************//

void main()
{
	 IE = 0x81;
	 while(1);
}

//***********STOP****************//













