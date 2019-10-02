#include <reg51.h>

void delay(unsigned int time)
{
	unsigned int i;
	TMOD = 0x21;
	for(i=0;i<time;i++)
	{
		TH0 = 0xFC;
		TL0 = 0x66;
		TR0 = 1;
		while(TF0 == 0);
		TR0 = 0;
		TF0 = 0;
	}
}