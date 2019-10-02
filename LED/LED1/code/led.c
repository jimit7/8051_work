#include <reg51.h>
#include "delay.h"

sbit LED = P1^0;

void main()
{
	while(1)
	{
		LED = 0;
		delay(1000);
		LED = 1;
		delay(1000);
	}
}