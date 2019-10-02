
 #ifndef __lcd_H
#define __lcd_H

#define LCDport P1

sbit RS = P3^2;
sbit RW = P3^3;
sbit EN = P3^4;

void lcdbegin(void);
void lcdcmd(char);
void lcddata(char);
void lcdprint(char *);
void lcdclear(void);
void lcdsetCursor(char,char);
void lcdwrite(unsigned int);
#endif
