#include <reg51.H>
sfr ldata = 0xB0;            //P3 = LCD data pins
sbit rs = P2^3;
sbit rw = P2^4;
sbit en = P2^5;

// start of ADC  group
sbit wr = P2^0;               //START 
sbit intr=P2^1;	               //EOC 
sbit rd = P2^2;	               //output enable 
// end of ADC group

unsigned char  present_sample,previous_sample;
unsigned char  x; 
unsigned char  up_sample,down_sample,mid_sample;  

code unsigned char line1[16]=" Solar Tracking ";
code unsigned char line2[16]="--developed by--";
code unsigned char line3[16]=" Neel Dhrumit";
code unsigned char line4[16]=" Meet Ankit";  



void lcdcmd (unsigned char value);
void lcddata (unsigned char value);
void msdelay (unsigned int itime);

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

void lcdcmd (unsigned char value)
{
	ldata = value;		// put value on the pins
	rs = 1;
	rw = 0;
	en = 1;			// strobe the enable pin
	msdelay(1);
	en = 0;
	return;
}


void lcddata (unsigned char value)
{
	ldata = value;		// put the value on the pins
	rs = 0; 
	rw = 0;
	en = 1;			// strobe the enable pin
	msdelay(1);
	en = 0;
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





void main (void)
{
	lcdcmd(0x38);		             // 2 line & 5*7 matrix
	msdelay(1);
	lcdcmd(0x0C);	             // display on cursor off
	msdelay(1);
	lcdcmd(0x01);		             // clear display screen
	msdelay(1);
    
	lcdcmd(0x80);		              // line 1, position 0
	msdelay(1);

	for(k=0;k<16;k++)
	{
		lcddata(line1[k]);
		msdelay(1);
	}

	lcdcmd(0xC0);		// line 2, position 0
	msdelay(1);

	for(k=0;k<16;k++)
	{
		lcddata(line2[k]);
		msdelay(1);
	}

	msdelay(10000);

	lcdcmd(0x80);		             // line 1, position 0
	msdelay(1);

	for(k=0;k<16;k++)
	{
		lcddata(line3[k]);
		msdelay(1);
	}






	lcdcmd(0xC0);		 // line 2, position 0
	msdelay(1);

	for(k=0;k<16;k++)
	{
		lcddata(line4[k]);
		msdelay(1);
	}

	msdelay(10000);

	lcdcmd(0x80);		              // line 1, position 0
	msdelay(1);

	

	msdelay(10000);


	present_sample = previous_sample = 0;
   	P1=0xFF;
    step = 0;
   	
	P1 = stepper_code[step];                                   // panel rotate
	msdelay(1000);
	inputting();
    previous_sample = x;







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
				
		if( step < 0){
				 step = 3;
				P1 = stepper_code[step]; // panel rotate
				msdelay(3000);
		    	inputting();
				mid_sample = x;
				
		step--;
		}
				
if( step < 0){
				 step = 3;
				P1 = stepper_code[step]; // panel rotate
				msdelay(3000);
		    	inputting();
				down_sample = x;
				
		step++;
		}
				
if( step > 3){
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
				 step = 0;
			             P1 = stepper_code[step];
				msdelay(3000);
		    	inputting();
				present_sample = x;
			
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
		 		step = 3;
				P1 = stepper_code[step];
				msdelay(3000);
			  inputting();
				present_sample = x;
               
				




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






