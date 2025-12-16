 
 	#include <91x_lib.h> 
 
 /* ADC Setup                                                                */
   void Int_a2d(void)
  
   {
    int n;
  
  
		 /* ADC Setup                                                                */
  SCU->GPIOIN[4]  |= 0x01;                /* P4.0 input  - mode 0             */

  GPIO4->DDR      &= 0xFE;                /* P4.0 direction - input           */

    SCU->GPIOANA    = 0x0001;              /* P4.0 analog mode ON              */ 
		
  for (n = 0; n < 100000; n ++);          /* Wait > 1 ms  (at 96 MHz)         */

  for (n = 0; n < 1500; n ++);            /* Wait > 15 us (at 96 MHz)         */
  ADC->CR         = 0x0002;              /* Set POR bit ,disEnable end of conversion interupt, Clear STB bit          */
  for (n = 0; n < 100000; n ++);          /* Wait > 1 ms  (at 96 MHz)         */
	
  ADC->CCR         = 0x0003;              /* AD Conversion, No WDG on Ch 0    */
  }