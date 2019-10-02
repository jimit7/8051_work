#include <reg51.h>
#include "delay.h"

sbit MP = P1^0;
sbit MN = P1^1;

void main()
{
	while(1)
	{
		MP = 1;
		MN = 0;

		delay(3000);

		MP = 0;
		MN = 1;

		delay(3000);

	}
}