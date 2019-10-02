//************************************//

//NAME:   
//TITLE:  GEERATE SAW TOOTH WAVE.
//DATE:   19/01/2014


//***********************************//

//***********START****************//

#include <reg51.h>
#include "delay.h"



//********MAIN PROGRAM***********//

void main()
{
	P2 = 0x00;

	while(1)
	{
		P2++;
		delay(10);
	
	}
}


//********START***********//