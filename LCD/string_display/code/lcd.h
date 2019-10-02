#ifndef __lcd_H
#define __lcd_H

#define LCDport P1

sbit RS = P2^0;
sbit RW = P2^1;
sbit EN = P2^2;

void lcdbegin(void);
void lcdcmd(char);
void lcdprint(char *);
void lcdsetCursor(char,char);

#endif
