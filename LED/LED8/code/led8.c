#include <reg51.h>
#include "delay.h"

void main()
{
	while(1)
	{
		P1 = 0xFF;
		delay(1000);
		P1 = 0x00;
		delay(1000);
	}
}