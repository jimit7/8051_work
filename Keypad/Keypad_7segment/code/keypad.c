#include <reg51.h>
#include "keypad.h"

void delay_us(int a)
{
   int i;
   for(i=0;i<a;i++);   //null statement
}

char read_key(void)					//	 0xC0,0xF9,0xA4,0xB0,0x99,0x92,0x82,0xF8,0x80,0x90 
{	
	RowA = 0; RowB = 1; RowC = 1; RowD = 1; 	//Test Row A

	if (C1 == 0) { delay_us(10000); while (C1==0); return 0xC0; }
	if (C2 == 0) { delay_us(10000); while (C2==0); return 0xF9; }
	if (C3 == 0) { delay_us(10000); while (C3==0); return 0xA4; }
	if (C4 == 0) { delay_us(10000); while (C4==0); return 0xB0; }

	RowA = 1; RowB = 0; RowC = 1; RowD = 1; 	//Test Row B

	if (C1 == 0) { delay_us(10000); while (C1==0); return 0x99; }
	if (C2 == 0) { delay_us(10000); while (C2==0); return 0x92; }
	if (C3 == 0) { delay_us(10000); while (C3==0); return 0x82; }
	if (C4 == 0) { delay_us(10000); while (C4==0); return 0xF8; }
	
	RowA = 1; RowB = 1; RowC = 0; RowD = 1; 	//Test Row C

	if (C1 == 0) { delay_us(10000); while (C1==0); return 0x80; }
	if (C2 == 0) { delay_us(10000); while (C2==0); return 0x90; }
	if (C3 == 0) { delay_us(10000); while (C3==0); return '3'; }
	if (C4 == 0) { delay_us(10000); while (C4==0); return '-'; }
	
	RowA = 1; RowB = 1; RowC = 1; RowD = 0; 	//Test Row D

	if (C1 == 0) { delay_us(10000); while (C1==0); return 'C'; }
	if (C2 == 0) { delay_us(10000); while (C2==0); return '0'; }
	if (C3 == 0) { delay_us(10000); while (C3==0); return '='; }
	if (C4 == 0) { delay_us(10000); while (C4==0); return '+'; }

	return 'n';           	// Means no key has been pressed
}

char get_key()
{
	 char key;
	 key = 'n';
	 while(key == 'n')
	 {
	 	key = read_key();       // Get pressed key
	 }
	 return key;
}
