/*
******************************************************************************
File:     main.c
Info:     Generated by Atollic TrueSTUDIO(R) 6.0.0   2016-09-27

The MIT License (MIT)
Copyright (c) 2009-2016 Atollic AB

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
******************************************************************************
*/

/* Includes */
#include <stddef.h>
#include "stm32l1xx.h"
#define S1 0
#define S2 1
#define S3 2


/* Private typedef */
/* Private define  */
/* Private macro */
/* Private variables */
/* Private function prototypes */
/* Private functions */


/**
**===========================================================================
**
**  Abstract: main program
**
**===========================================================================
*/
int main(void)
{
  int i = 0;
  int pocetStlaceni = 0;

  /**
  *  IMPORTANT NOTE!
  *  See the <system_*.c> file and how/if the SystemInit() function updates 
  *  SCB->VTOR register. Sometimes the symbol VECT_TAB_SRAM needs to be defined 
  *  when building the project if code has been located to RAM and interrupts 
  *  are used. Otherwise the interrupt table located in flash will be used.
  *  E.g.  SCB->VTOR = 0x20000000;  
  */

  /**
  *  At this stage the microcontroller clock setting is already configured,
  *  this is done through SystemInit() function which is called from startup
  *  file (startup_stm32l1xx_hd.s) before to branch to application main.
  *  To reconfigure the default setting of SystemInit() function, refer to
  *  system_stm32l1xx.c file
  */

  /* TODO - Add your application code here */
  	  RCC_AHBPeriphClockCmd(RCC_AHBPeriph_GPIOA, ENABLE);
    RCC_AHBPeriphClockCmd(RCC_AHBPeriph_GPIOC, ENABLE);
    GPIO_InitTypeDef gpioInitStruc;
    gpioInitStruc.GPIO_Mode = GPIO_Mode_OUT;
    gpioInitStruc.GPIO_OType = GPIO_OType_PP;
    gpioInitStruc.GPIO_Pin = GPIO_Pin_5;
    gpioInitStruc.GPIO_Speed = GPIO_Speed_400KHz;

    GPIO_Init(GPIOA, &gpioInitStruc);
    GPIO_SetBits(GPIOA, GPIO_Pin_5);


    gpioInitStruc.GPIO_Mode = GPIO_Mode_IN;
  //  gpioInitStruc.GPIO_OType = GPIO_OType_PP;
    gpioInitStruc.GPIO_Pin = GPIO_Pin_13;
    gpioInitStruc.GPIO_PuPd = GPIO_PuPd_UP;
    gpioInitStruc.GPIO_Speed = GPIO_Speed_40MHz;
    GPIO_Init(GPIOC, &gpioInitStruc);


    uint8_t buttonState = GPIO_ReadInputDataBit(GPIOC, GPIO_Pin_13);

  int BUTTON = 0;
  /*

  RCC_AHBPeriphClockCmd(RCC_AHBPeriph_GPIOA, ENABLE);
  RCC_AHBPeriphClockCmd(RCC_AHBPeriph_GPIOC, ENABLE);


  GPIOA->MODER |= (0b01)<<(5*2);
  GPIOA->OTYPER &= ~((uint16_t)(1<<5));
  GPIOA->PUPDR |= (0b01)<<(5*2);
  GPIOA->OSPEEDR |= (0b10)<<(5*2);


  GPIOC->MODER |= (0b00)<<(13*2);
  GPIOC->OTYPER &= ~((uint16_t)(1<<13));
  GPIOC->PUPDR |= (0b00)<<(13*2);
  GPIOC->OSPEEDR |= (0b10)<<(5*2);

  int stary = 0;
  int novy = 0;*/
  /* Infinite loop */
  while (1)
  {
	  /*
	  GPIOA->ODR |= ((uint16_t)(1 << 5));

	  GPIOA->ODR &= ~((uint16_t)(1 << 5));

	  GPIOA->BSRRL |= ((uint16_t)(1 << 5));

	  GPIOA->BSRRH |= ((uint16_t)(1 << 5));*/
/*
	  if ((GPIOC->IDR &= ((uint16_t)(1 << 13)))){
		  BUTTON = 0;
	  }
	  else
		  BUTTON = 1;*/
/*
	  for (i=0; i<100000; i++){
		  if (i < 50000){
			  GPIOA->ODR |= ((uint16_t)(1 << 5));
		  }
		  else{
			  GPIOA->ODR &= ~((uint16_t)(1 << 5));
		  }
	  }*/
/*
	  if ((GPIOC->IDR &= ((uint16_t)(1 << 13)))){
		  GPIOA->ODR &= ~((uint16_t)(1 << 5));
	  }
	  else
		  GPIOA->ODR |= ((uint16_t)(1 << 5));
	*/

	  /************************************************
	  if (!(GPIOC->IDR &= ((uint16_t)(1 << 13)))){
		  pocetStlaceni++;



		  if (pocetStlaceni>4 && (GPIOA->IDR &= ((uint16_t)(1 << 5)))){
			  GPIOA->ODR &= ~((uint16_t)(1 << 5));
	  	  }
	  	  else
	  		  GPIOA->ODR |= ((uint16_t)(1 << 5));
	  }
	  *************************************************/
/*
	  int j = 0;

	  int vyjdizCyklu = 0;
	  uint8_t cState = 0;
	  uint8_t in;
	  uint8_t it = 0;
	  in = (!(GPIOC->IDR &= ((uint16_t)(1 << 13))));

	  stary = novy;
	  novy = ((GPIOC->IDR &0b1<<13) >> 13);

	  if ((stary == 1)&&(novy == 0)){
		  GPIOA->ODR ^=0b1<<5;
	  }*/
/*
	  buttonState = GPIO_ReadInputDataBit(GPIOC, GPIO_Pin_13);
	 	  if (buttonState == 0){
	 		  GPIO_SetBits(GPIOA, GPIO_BSRR_BS_5);
	 	  }
	 	  else
	 		  GPIO_ResetBits(GPIOA, GPIO_BSRR_BS_5);
	 	  */
	  buttonState = GPIO_ReadInputDataBit(GPIOC, GPIO_IDR_IDR_13);

	  if (buttonState == 1){
	 	 BUTTON = 0;
	  }
	  else
	  	 BUTTON = 1;
  }
  return 0;
}

#ifdef  USE_FULL_ASSERT

/**
  * @brief  Reports the name of the source file and the source line number
  *   where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t* file, uint32_t line)
{
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */

  /* Infinite loop */
  while (1)
  {
  }
}
#endif

/*
 * Minimal __assert_func used by the assert() macro
 * */
void __assert_func(const char *file, int line, const char *func, const char *failedexpr)
{
  while(1)
  {}
}

/*
 * Minimal __assert() uses __assert__func()
 * */
void __assert(const char *file, int line, const char *failedexpr)
{
   __assert_func (file, line, NULL, failedexpr);
}
