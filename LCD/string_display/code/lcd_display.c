#include <reg51.h>
#include "lcd.h"
#include "delay.h"

void main()
{

	lcdbegin();
	lcdsetCursor(4,0);
	lcdprint("Jignesh");

//	lcdcmd(0xC0);
	lcdsetCursor(5,1);
	lcdprint("Patoliya");
	while(1);
}