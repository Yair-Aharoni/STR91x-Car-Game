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
		

		 int measure(void);// measure p4.0 analog return 10 bit integer
		 void dly(int i); //delay function depended by i

         void dly(int i)
		 {
		  int j,k;
		  for (j=1;j<100;j++)
		  {
		  for(k=0;k<i;k++);
		  }
		  }

		

       int measure(void)
		 {
		  ADC->CR         &= 0xFF7f; 
      ADC->CR         = 0x0002;	
		
      ADC->CR         |= 0x0001;	 
			 	 dly(10000);
			 
      while(	((ADC->CR) & 0x8000)==0); // wait for end of converge
			 
       return ((ADC->DR0) & 0x03FF);			 
		  }
		  
			
int main (void) 
   {
  unsigned int  n=1,td=1000;
		 
    Intio();
		 Int_a2d();
		 LED=0xf;
  while (1) 
       { 
        				 
				LED=(measure()>>2);
	  dly(td);  

  }
}
