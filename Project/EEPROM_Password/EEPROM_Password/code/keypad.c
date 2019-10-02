#include <reg51.h>
#include "keypad.h"

void delay_us(int a)
{
   int i;
   for(i=0;i<a;i++);   //null statement
}

char read_key(void)	
{	
	RowA = 0; RowB = 1; RowC = 1; RowD = 1; 	//Test Row A

	if (C1 == 0) { delay_us(10000); while (C1==0); return '0'; }
	if (C2 == 0) { delay_us(10000); while (C2==0); return '1'; }
	if (C3 == 0) { delay_us(10000); while (C3==0); return '2'; }
	if (C4 == 0) { delay_us(10000); while (C4==0); return '3'; }

	RowA = 1; RowB = 0; RowC = 1; RowD = 1; 	//Test Row B

	if (C1 == 0) { delay_us(10000); while (C1==0); return '4'; }
	if (C2 == 0) { delay_us(10000); while (C2==0); return '5'; }
	if (C3 == 0) { delay_us(10000); while (C3==0); return '6'; }
	if (C4 == 0) { delay_us(10000); while (C4==0); return '7'; }
	
	RowA = 1; RowB = 1; RowC = 0; RowD = 1; 	//Test Row C

	if (C1 == 0) { delay_us(10000); while (C1==0); return '8'; }
	if (C2 == 0) { delay_us(10000); while (C2==0); return '9'; }
	if (C3 == 0) { delay_us(10000); while (C3==0); return 'A'; }
	if (C4 == 0) { delay_us(10000); while (C4==0); return '-'; }
	
	RowA = 1; RowB = 1; RowC = 1; RowD = 0; 	//Test Row D

	if (C1 == 0) { delay_us(10000); while (C1==0); return 'B'; }
	if (C2 == 0) { delay_us(10000); while (C2==0); return '0'; }
	if (C3 == 0) { delay_us(10000); while (C3==0); return '='; }
	if (C4 == 0) { delay_us(10000); while (C4==0); return '+'; }

	return 'n';           	// Means no key has been pressed
}

char get_key(void)           //get key from user
{
	char key1 = 'n';              //assume no key pressed

	while(key1=='n')              //wait untill a key is pressed
		key1 = read_key();   //scan the keys again and again

	return key1;                  //when key pressed then return its value
}
