#include <reg51.h>
#include "keypad.h"
#define LEDs P2
int main(void)
{
   char key;                // key char for keeping record of pressed key

   
   while(1)
   { 
     key = get_key();
	 LEDs = key;
   }
}