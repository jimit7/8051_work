#include <reg51.h>
#include "delay.h"
#include "ADC0808.h"

// Function Purpose: Produce approximate delay in given uSecs.
void __delay_us(unsigned int d)
{
   unsigned int i, limit;
   limit = d/15;

   for(i=0;i<limit;i++);
}

void ADCbegin(void)
{
	Add_A = 0;		  // Make output
	Add_B = 0;		  // Make output 
	Add_C = 0;		  // Make output
	ALE   = 0;		  // Make output
	EOC   = 1;		  // Make input
	OE    = 0;		  // Make output
	START = 0;		  // Make output
	CLK   = 0;		  // Make output
	
	Data_Bus = 0xFF;  // Make Inputs	
}



unsigned char analogRead(unsigned char Channel)
{
	unsigned int i = 0;
	unsigned int ADC_value = 0;

	// Select Channel
	switch(Channel)
	{
	case A0: Add_C = 0;  Add_B = 0;  Add_A = 0; break;
	case A1: Add_C = 0;  Add_B = 0;  Add_A = 1; break;
	case A2: Add_C = 0;  Add_B = 1;  Add_A = 0; break;
	case A3: Add_C = 0;  Add_B = 1;  Add_A = 1; break;
	case A4: Add_C = 1;  Add_B = 0;  Add_A = 0; break;
	case A5: Add_C = 1;  Add_B = 0;  Add_A = 1; break;
	case A6: Add_C = 1;  Add_B = 1;  Add_A = 0; break;
	case A7: Add_C = 1;  Add_B = 1;  Add_A = 1; break;
	}	   

	__delay_us(HalfCycleDelay);		// 250kHz Frequency
	ALE = 1;						// Enable Address Latch
	CLK = 1; 						// Make CLK High
	__delay_us(HalfCycleDelay);		// 250kHz Frequency
	CLK = 0; 						// Make CLK Low
	START = 1;						// Start ADC Conversion
	__delay_us(HalfCycleDelay);		// 250kHz Frequency
	CLK = 1; 						// Make CLK High
	ALE = 0;						// Disable Address Latch
	__delay_us(HalfCycleDelay);		// 250kHz Frequency
	CLK = 0; 						// Make CLK Low
	START = 0;						// Complete the start pulse

	for(i=0;i<2000;i++)
	{
		CLK = !CLK;					// Toggle Clock
		__delay_us(HalfCycleDelay);	// 250kHz Frequency

		if(!EOC)		  			// Wait for EOC to be low
			break;
	}

	for(i=0;i<2000;i++)
	{
		CLK = !CLK;					// Toggle Clock
		__delay_us(HalfCycleDelay);	// 250kHz Frequency

 		if(EOC)					   	// Wait for EOC to be High	
			break;
	}

	CLK = 0; 						// Make CLK Low
	OE = 1;							// Enable Output
	__delay_us(HalfCycleDelay);		// 250kHz Frequency
	CLK = 1; 						// Make CLK High
	__delay_us(HalfCycleDelay);		// 250kHz Frequency
	CLK = 0; 						// Make CLK Low
	__delay_us(HalfCycleDelay);		// 250kHz Frequency
	CLK = 1; 						// Make CLK High

	ADC_value = Data_Bus;			// Read value

	__delay_us(HalfCycleDelay);		// 250kHz Frequency
	OE = 0;							// Disable Output
	CLK = 0; 						// Make CLK Low
	__delay_us(HalfCycleDelay);		// 250kHz Frequency

	return ADC_value;		 		// Return ADC value
}