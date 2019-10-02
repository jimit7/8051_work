#include <reg51.h>
#include "lcd.h"
#include "delay.h"

// start of ADC  group
sbit wr = P2^0;               //START 
sbit intr=P2^1;	               //EOC 
sbit rd = P2^2;	               //output enable 
// end of ADC group

unsigned char  present_sample,previous_sample;
unsigned char  x; 
unsigned char  up_sample,down_sample,mid_sample;  

void inputting();

code unsigned char stepper_code[4]={0xfe,0xfb,0xfd,0xf7};

signed char step;
unsigned char k;

void msdelay (unsigned int itime)
{
	unsigned int i,j;
	for(i=0; i<itime; i++)
	{
		for(j=0; j<100; j++)
		{;}                 // no operation
	}

	return;
}

void inputting()
{ 	
          //Code for ADC input
    P0 = 0xFF;
	intr = 1;
	rd = 1;
	wr = 1;
	msdelay(1);
	wr=0;
	msdelay(1);
	wr = 1;	
	while(intr == 1);
	msdelay(10);             // this delay is to allow completion of ADC process
	rd = 0;
	msdelay(1);
	rd = 1;	 
	x = P0;
	 
	 return;
}

void main()
{

	lcdbegin();

	lcdsetCursor(0,0);
	lcdprint("Tracking of");
	lcdsetCursor(1,1);
	lcdprint("Solar Panel");
	delay(3000);

	lcdclear();
	lcdsetCursor(0,0);
	lcdprint("With Respect to");
	lcdsetCursor(1,1);
	lcdprint("Light Intensity");
	delay(3000);

	lcdclear();

	lcdsetCursor(0,0);
	lcdprint("Prepared By:- ");
	delay(2000);

	lcdclear();
	lcdprint("Neel   Dhrumit");
	lcdsetCursor(1,1);
	lcdprint("Ankit   Meet");
	delay(3000);

	lcdclear();
	lcdprint("Guided By:-     ");
	lcdsetCursor(1,1);
	lcdprint("Prof.H.K.Jadeja");
	delay(4000);

	lcdclear();
	lcdprint("Solar Power sys  ");
	
	while(1)
	{
	
		step++;
		if( step > 3)
		{
			 step = 0;
			 P1 = stepper_code[step]; // panel rotate
			 msdelay(3000);
		     inputting();
			 up_sample = x;
			 step--;	
				
		}
				
		if( step < 0)
		{
			 step = 3;
			 P1 = stepper_code[step]; // panel rotate
			 msdelay(3000);
		     inputting();
			 mid_sample = x;
				
		     step--;
		}
				
       if( step < 0)
	   {
				 step = 3;
				P1 = stepper_code[step]; // panel rotate
				msdelay(3000);
		    	inputting();
				down_sample = x;
				
				step++;
		}
				
		
		
		if( step > 3)
		{
				step = 0;
				P1 = stepper_code[step]; // panel rotate
				msdelay(3000);
			    inputting();
				previous_sample = x;
		}
			




  	else if(up_sample > mid_sample)
    { 
				
		LOOP1:
			step++;
			if( step > 3)
			{
				 step = 0;
				 P1 = stepper_code[step];
				 msdelay(3000);
		    	 inputting();
				 present_sample = x;
			}
			if(present_sample > previous_sample)
				{
					previous_sample = present_sample;
			   		goto  LOOP1;
       			}
				else
				{
				 	step--;
				 	if( step < 0)
				  	step = 3;
					P1 = stepper_code[step]; // panel rotate
					msdelay(3000);
					inputting();
					previous_sample = x;
				}
		   }
	

	else if(down_sample > mid_sample)
	{ 
		LOOP2:
		step--;
		if( step == -1)
		{
		 	step = 3;
			P1 = stepper_code[step];
			msdelay(3000);
			inputting();
			present_sample = x;
        	
	 	 }
			if(present_sample > previous_sample)
			{
				previous_sample = present_sample;
				goto  LOOP2;
			}
			else
			{
				step++;
				if( step > 3)
				step = 0;
	    		P1 = stepper_code[step];
	    		msdelay(3000);
	    		inputting();
				previous_sample = x;
			}  

		}
	      	
		  msdelay(10000);
	   }
	
}