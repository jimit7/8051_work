#ifndef __lcd_H
#define __lcd_H

#define LCDport P3

sbit RS = P2^3;
sbit RW = P2^4;
sbit EN = P2^5;

void lcdbegin(void);
void lcdcmd(char);
void lcdprint(char *);
void lcdsetCursor(char,char);
void lcdclear();

#endif
