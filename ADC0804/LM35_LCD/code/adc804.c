#include<reg51.h>
#include "adc804.h"

void adcInit()
{
	DATAPORT = 0xFF;
	INTR = 1;
 	WRITE = 1;
 	READ = 1;
}

unsigned char analogRead(void)
{
	READ = 1;
	WRITE = 0;						//start of conversion;
	WRITE = 1;
	while(INTR == 1);				//wait for conversion,when conversion complate,INTR low; 
	READ = 0;						//start to read data;

	return DATAPORT;
}