//************************************//

/*NAME:   VARA ASHISH H.
  TITLE:  GENERATE FOLLOWING TASK USING INTERRUPT:

		 1) RECEIVE DATA SERIALLY AND SEND IT TO P0 
		 2) READ PORT P1 AND TRANSMIT SERIALLY AND GET COPY TO P2
		 3) MAKE TIMER 0 TO GENERATE SQUARE WAVE OF FREQUENCY 5kHz ON P3.7

  DATE:  07/01/2014 */

//***********************************//

//***********START****************//

#include<reg51.h>
sbit wave = P3^7;
int count = 0;
unsigned char a;


//***********INTERRUPT FOR TIMER 0****************//

void timer0() interrupt 1
{
	wave = ~wave;

	TH0 = 0xFF;
	TL0 = 0x48;
}

//***********INTERRUPT FOR SERIAL COMUNICATION****************//

void serial0() interrupt 4
{
	if(TI == 1)
	{
		
		TI = 0;
		SBUF = a;
		
	}
	else
	{
		P0 = SBUF;
		RI = 0;
		
	}
}

//**************MAIN PROGRAM****************//

void main()
{
	
	P1 = 0xFF;
	IE = 0x92;			//enable timer0 and seial communication interrupt;
	SCON = 0x50;			//for serial communication;
	TMOD = 0x21;			//configure timer0 in mode 1 and timer1 in mode 2;
	TH1 = 0xFD;			//load value of 9600 baudrate for timer1;
	TH0 = 0xFF;			//load value for 5kHz pulse
	TL0 = 0x48;
	TR1 = 1;			//timer1 start;
	TR0 = 1;			//timer0 start;
				
	SBUF = a;			//ger data from p1 and transmit serialy;
	while(1)
	{
		
		a = P1;
		P2 = a;			//ger data from p1 and send it to p2;
					
	}			
	
					
}

//**************STOP****************//