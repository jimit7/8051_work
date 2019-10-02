#ifndef __adc804_H
#define __adc804_H

#define DATAPORT P2

sbit INTR = P3^5;
sbit WRITE = P3^6;
sbit READ = P3^7;

void adcInit(void);
unsigned char analogRead(void);
#endif