//************************************//

//NAME:   
//TITLE:  GENERATE STAIR CASE WAVE.
//DATE:   19/01/2014


//***********************************//

//***********START****************//

#include <reg51.h>
#include "delay.h"


//********MAIN PROGRAM***********//

void main()
{
	unsigned char z; 
	while(1)
	{
		for(z=0;z<255;z+=51)
		{
			P2 = z;
			delay(10);
		}

		for(z=255;z>0;z-=51)
		{
			P2 = z;
			delay(10);
		}	
	}
}


//********START***********//