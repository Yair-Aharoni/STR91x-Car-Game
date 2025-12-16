/******************************************************************************/
/* BLINKY.C: LED Flasher for MCB-STR9 Board                                   */
/******************************************************************************/
/* This file is part of the uVision/ARM development tools.                    */
/* Copyright (c) 2005-2006 Keil Software. All rights reserved.                */
/* This software may only be used under the terms of a valid, current,        */
/* end user licence from KEIL for a compatible version of KEIL software       */
/* development tools. Nothing else gives you the right to use this software.  */
/******************************************************************************/

#include <91x_lib.h> 
      
		  #define   LED		GPIO7->DR[0x3FC]
		  #define   SW		GPIO3->DR[0x3FC]
		

		 
		 void dly(int i);

         void dly(int i)
		 {
		  int j,k;
		  for (j=1;j<100;j++)
		  {
		  for(k=0;k<i;k++);
		  }
		  }

int main (void) 
   {
  unsigned int  n=1,td=10000;
	unsigned char Nline, Place=0,tav;	 
    Intio();
		lcd_init ();// initial the LCD display 
  while (1) 
       {   
				if ((SW&0X40)!=0) Nline=0;
          else Nline=1;				 
	set_cursor ( Place,Nline);			 
        if ((SW&0X20)!=0) tav='@';
				 else tav='+';
				 lcd_putchar (tav);
				 Place=(Place+1)%15;
	  dly(td);  
LED=SW;
  }
}
