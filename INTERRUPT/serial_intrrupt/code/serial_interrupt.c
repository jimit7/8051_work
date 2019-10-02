//************************************//

/*NAME:   VARA ASHISH H.
  TITLE:  GENERATE FOLLOWING TASK USING INTERRUPT:

		 1) CREATING SQUARE WAVE ON P2.5 
		 2) SENDING LATTER 'A' TO SERIAL PORT
		 3) GET SINGLE BIT FROM P1.7 AND SEND IT TO P1.0

  DATE:  07/01/2014 */

//***********************************//

//***********START****************//

#include<reg51.h>
sbit wave = P2^5;
sbit LED = P1^0;
sbit SW = P1^7;


//***********INTERRUPT FOR TIMER 0****************//

void timer0() interrupt 1
{
	wave = ~wave;
	TH0 = 0xFC;
	TL0 = 0x66;
}

//***********INTERRUPT FOR SERIAL COMUNICATION****************//

void serial0() interrupt 4
{
	if(TI == 1)
	{
		
		TI = 0;
		SBUF = 'A';
		
	}
	else
	{
		RI = 0;
	}
}

//**************MAIN PROGRAM****************//

void main()
{
	SW = 1;
	IE = 0x92;			//enable timer0 and seial communication interrupt;
	SCON = 0x50;			//for serial communication;
	TMOD = 0x21;			//configure timer0 in mode 1 and timer1 in mode 2;
	TH1 = 0xFD;			//load value of 9600 baudrate for timer1;
	TH0 = 0xFC;			//load value for 1ms pulse
	TL0 = 0x66;
	TR1 = 1;			//timer1 start;
	TR0 = 1;			//timer0 start;
	SBUF = 'A';			//transmit latter 'A';
	while(1)
	{
		LED = SW;		//ger data from p1.7 and send it to p1.0;
	}
}

//**************STOP****************//