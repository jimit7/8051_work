#include <reg51.h>
#include "delay.h"
#include "ADC0808.h"

#define Seg_port P1

void display_7segment(unsigned char);

sbit E1 = P3^5;
sbit E2 = P3^6;
sbit E3 = P3^7;

char num[] = {0xC0,0xF9,0xA4,0xB0,0x99,0x92,0x82,0xF8,0x80,0x90  };

// Main function
void main()
{
	unsigned char Dout = 0;	 	// To capture ADC value
	

	ADCbegin();							// Initialize ADC
	delay(1);

	while(1)
	{
		Dout = analogRead(A1);		// Read ADC value from Channel 1

		display_7segment(Dout);

	//	delay(1000);												 // Delay of one second
	}
}

void display_7segment(unsigned char i)
{
	
	E1 = 1;
	Seg_port = num[i / 100];
	delay(1);
	E1 = 0;

	E2 = 1;
	Seg_port = num[(i % 100) / 10];
	delay(1);
	E2 = 0;

	E3 = 1;
	Seg_port = num[(i % 100) % 10];
	delay(1);
	E3 = 0;
}