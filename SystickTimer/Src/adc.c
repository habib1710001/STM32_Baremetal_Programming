/*
 * adc.c
 * for A2
 *  Created on: 16 Nov. 2022
 *      Author: Habib Ur Rahman
 */
#include "stm32f4xx.h"
#include "stdint.h"
#include "adc.h"

#define GPIOAEN (1U << 0)
#define MASK(x) (1U << x)
#define ADC1EN  (1U << 8)
#define ADC_SQ1   0x04
#define ADC_CONV_LEGNTH 0x00
#define ADON (1U << 0)
#define SWSTART (1U << 30)
#define SR_EOC  (1U << 1)
#define COUNT    (1U << 1)


void pa4_adc_init(void){

///** Configuring port registers******///

	//Enabling clock for port A
     RCC-> AHB1ENR |= GPIOAEN;

    //Enabling analog mode on the PORTA
     GPIOA -> MODER |= MASK(9);
     GPIOA -> MODER |= MASK(8);

///** Configuring ADC functionalities *****///

     //Enabling Clock for the ADC
     RCC-> APB2ENR |= ADC1EN;

     //Configuring the sequence registers
     //sequence of the channels
     ADC1-> SQR3 |= ADC_SQ1 ;

     //Configuring number of channel to be converter
     ADC1-> SQR1 |= ADC_CONV_LEGNTH;

     // Configuring the control register to enable the ADC
     ADC1 -> CR2 |= ADON ;

}



void start_conversion(void){
  //Enabling Continuous conversion Mode
	ADC1 -> CR2 |= COUNT ;
  // Start conversion
	ADC1 -> CR2 |= SWSTART ;
}

uint32_t read_adc(void){

//Halt reading until the conversion is done
//By configuring the EOC bit
 while(!(ADC1 -> SR & SR_EOC));

 //Reading the ADC
 return (ADC1 -> DR);
}

