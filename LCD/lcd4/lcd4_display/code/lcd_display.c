#include <reg51.h>
#include "lcd.h"
#include "delay.h"

void main()
{

	lcdbegin();
	lcdprint("Jignesh");

	lcdcmd(0xC0);
	lcdprint("Patoliya");
	while(1);
}