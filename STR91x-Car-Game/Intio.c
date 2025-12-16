

    
    #include <91x_lib.h> 

  void Intio(void);
		 
		  void Intio(void)

  {
   int n;
 /* General Purpose I/O Port 7 Setup (LED)*/
  SCU->GPIOOUT[7] = 0x5555;               /* P7.0..7 output - mode 1          */
  GPIO7->DDR      = 0xFF;                 /* P7.0..7 Outputs (LED Data)       */
  GPIO7->DR[0x3FC]= 0x00;                 /* clear LEDs                       */

  /* General Purpose I/O Port 8,9 Setup (LCD)*/
  GPIO8->DDR      = 0xFF;                 /* P8.0..7 Outputs (LCD Data)       */
  GPIO9->DDR      = 0x07;                 /* P9.0..2 Outputs (LCD Control)    */

  /* General Purpose I/O Port 3 Setup (Push Button)*/
  /* portA = S2 (P3.5 (INT5)), Port B = S3 (P3.6 (INT6)) */				    
  SCU->GPIOOUT[3] &= 0xC3FF;              /* P3.5, P3.6 input mode            */
  GPIO3->DDR      &= 0x9F;                /* P3.5, P3.6 Input Push Buttons)   */

 

	 /* ADC Setup                                                                */
  SCU->GPIOIN[4]  |= 0x01;                /* P4.0 input  - mode 0             */
 // SCU->GPIOOUT[4] &= 0xFFFC;              /* P4.0 output - mode 0             */
  GPIO4->DDR      &= 0xFE;                /* P4.0 direction - input           */
 // SCU->GPIOANA    |= 0x0001;              /* P4.0 analog mode ON              */
 
    SCU->GPIOANA    = 0x0001;              /* P4.0 analog mode ON              */ 
		
 // ADC->CR         |= 0x0002;              /* Set POR bit                      */
  for (n = 0; n < 100000; n ++);          /* Wait > 1 ms  (at 96 MHz)         */

 // ADC->CR         &= 0xFFF7;              /* Clear STB bit                    */
 
  for (n = 0; n < 1500; n ++);            /* Wait > 15 us (at 96 MHz)         */
  ADC->CR         = 0x0003;              /* Set POR bit ,Enable end of conversion interupt, Clear STB bit          */
  for (n = 0; n < 100000; n ++);          /* Wait > 1 ms  (at 96 MHz)         */
	
	
 // ADC->CR         |= 0x0400;              /* Enable end of conversion interupt*/
  ADC->CCR         = 0x0003;              /* AD Conversion, No WDG on Ch 0    */
  }