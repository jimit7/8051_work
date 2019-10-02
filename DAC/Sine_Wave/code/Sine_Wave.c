//************************************//

//NAME:   
//TITLE:  GENERATE SINE WAVE.
//DATE:   22/01/2014


//***********************************//

//***********START****************//

#include<reg51.h>
#include "delay.h"

#define DATAPORT P2

//********MAIN PROGRAM***********//

void main()
{
	char value[] = {128,150,172,192,210,226,239,248,254,255,
			254,248,239,226,210,192,172,150,128,
			106,84,64,46,30,17,8,2,0,2,8,17,30,46,64,84,106};
   while(1)
   {
		unsigned char z;

		for(z=0;z<36;z++)
		{
			DATAPORT = value[z];
			delay(10);
		}
   }

}			   


//********START***********//