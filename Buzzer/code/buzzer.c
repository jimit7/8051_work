#include <reg51.h>
#include "delay.h"

sbit buzzer = P1^0;

void main()
{
	while(1)
	{
		buzzer = 1;
		delay(1000);
		buzzer = 0;
		delay(1000);
	}
}