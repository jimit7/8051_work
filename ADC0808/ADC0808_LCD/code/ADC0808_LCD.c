#include <reg51.h>
#include "delay.h"
#include "lcd.h"
#include "ADC0808.h"

// Main function
void main()
{
	unsigned char Dout = 0;	 	// To capture ADC value
	

	ADCbegin();							// Initialize ADC
	lcdbegin();							// Initialize LCD display
	lcdsetCursor(0,1);
	lcdprint("Starting...");	// Show Welcome Message
	delay(1);						// 1 Sec delay
	lcdclear();					// Clear LCD

	while(1)
	{
		Dout = analogRead(A1);		// Read ADC value from Channel 1

	

	//	lcdclear();	
		lcdsetCursor(0,0);										// Clear LCD
		lcdprint("ADC value = ");							// Display string
		lcdwrite(Dout);

		delay(1000);												 // Delay of one second
	}
}
