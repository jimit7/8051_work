#include <reg51.h>
#include "keypad.h"
#include "delay.h"
#include "LCD.h"
#include "EEPROM.h"
#include "I2C.h"

sbit MP = P0^0;
sbit MN = P0^1;
sbit buzzer = P0^2;

char len = 4;
char count = 0,lock = 0;
char userPassword[];
char password[] = "123-"; 
char Mpassword[] = "1111"; 
char key;

void extrer0(void) interrupt 0
{

	
	lcdclear();
	lcdprint("set Pass:"); 
	count = 0;
		while(1)
		{
    	    
			key = get_key();
    		if(key)
			{
     
				EEPROMWrite(count, key);//   
			//	lcdcmd()  		
//				lcdsetCursor(count, 1);
      			lcddata(key);
      			delay(300);  // Debounce Delay
      			count++;
   			 }
			 	
			if(count == len)
      		break;
  		}

		password[0] = EEPROMRead(0);
		password[1] = EEPROMRead(1);
		password[2] = EEPROMRead(2);
		password[3] = EEPROMRead(3);
		
//		lcddata(password[0]);
//		lcddata(password[1]);
//		lcddata(password[2]);
//		lcddata(password[3]);
		delay(2000);
		lcdclear();
		count = 0;
	   lcdprint("Enter Pass:");
}



void main(void)
{
   unsigned char p = 0;
   lcdbegin();
   lcdclear();
   //lcdsetCursor(0,0);
   lcdprint("Hello");
  // while(1);
   	InitI2C();
    P1 = 0xF0;
	IE = 0x81;
   
   	password[0] = EEPROMRead(0);
	password[1] = EEPROMRead(1);
	password[2] = EEPROMRead(2);
	password[3] = EEPROMRead(3);
   
  

again:
    lcdclear();
	lcdprint("Enter Pass:"); 
  	count = 0;
	p = 0;
  	while(1)
	{
    
   	 key = get_key();
      if (key){
      userPassword[count] = key;
      //lcdsetCursor(count, 0);
      lcddata(key);
      delay(30);  // Debounce Delay
      count++;
    }
    if(count == len)
      break;
   }
  // delay(1000);
   count = 0;

   for(count = 0;count < len; count++)
   {
  	if(userPassword[count] == password[count])
	{
		p++;
	}
   }

  if(p == (len - 1))
  {
  	lcdclear();
	lcdprint("Door is Open");
	MP = 1;
	MN = 0;
	delay(1000);
	MP = 0;
	MN = 0;
	delay(3000);
	MP = 0;
	MN = 1;
	delay(1000);
	MP = 0;
	MN = 0;

	count = 0;
	goto again;
  }
  
  else
   {
   	  lcdclear();	
      lcdprint("Wrong password");
      delay(1000);
	  lcdclear();
     // lock++;
      count = 0;                                   // reset the password checking flag
     
	  if(lock<3)
      {
        lcdclear();

		if(lock == 0)
		{
			lcdclear();
			lcdprint("1st Trail over");
		}
		else if(lock == 1)
		{
			lcdclear();
			lcdprint("2nd Trail over");
		}


		else if(lock == 2)
		{
			lcdclear();
			lcdprint("Last Trail");
		}

		buzzer = 0;
		delay(500);
		buzzer = 1;
		lock++;
		count = 0;
		goto again;

      }
      else
      {
        lcdclear();
        lcdprint("System is locked");
        delay(2000);
        lcdclear();
        lcdprint("Enter Master Key");
//        lcdsetCursor(0,1);
		lcdcmd(0xC1);
        lcdprint("To Unlock System!");
        delay(2000);
        lcdclear();
        
		again1:
	 lcdclear();
	 lcdprint("Enter M_Pass:");
	 lcdcmd(0xc1);
	 count = 0;
		while(1)
		{
    
			char key = get_key();
	    	if (key){
	     	 userPassword[count]=key;
//	      	 lcdsetCursor(count, 1);
	     	 lcddata(key);
	      	 delay(300);  // Debounce Delay
	      	 count++;
	    	}
	      	if(count == len)
	     	break;
          }
 
  	count = 0;
  	p = 0;
  	for(count = 0;count < len; count++)
  	{
  		if(userPassword[count] == Mpassword[count])
		{
			p++;
		}
  	}

  	if(p == (len - 1))
  	{
  		lcdclear();
		lcdprint("System Unlock");
		count=0;
		goto again;
  	}
  	else 
  	{
    goto again1;
  	}      

    delay(1000);
   
}
}
}