/*
 * adc.c
 *
 *  Created on: 16 Nov. 2022
 *      Author: Habib Ur Rahman
 */
#include "stm32f4xx.h"
#include "adc.h"

#define ADC1EN  (1U<< 8)
#define GPIOAEN (1U<< 0)
#define ADC_CH1 (1U<< 0)
#define ADC_SEQ_LEN_1 0x00  //1 conversion
#define CR2_ADON (1U << 0)
#define CR2_SWSTART (1U << 30)
#define SR_EOC   (1U << 1 )

void pa1_adc_init(void){

	/*****configure the ADC GPIO pin*****/

	//Enable Clock Access to GPIOA
	RCC -> AHB1ENR |= GPIOAEN;

    //Set the mode of PA1 to analog
	GPIOA -> MODER |= (1U << 2);
	GPIOA -> MODER |= (1U << 3);

	/****configure the ADC module****/

	//Enable Clock Access to ADC
    RCC -> APB2ENR |= ADC1EN;

	//Configure ADC parameters

    //conversion sequence start
    ADC1-> SQR3 = ADC_CH1;

    //conversion sequence length
    ADC1-> SQR1 = ADC_SEQ_LEN_1;

    //enable the ADC module
    ADC1->CR2 |= CR2_ADON   ;

}





void start_conversion(void){

	/****start ADC conversion *****/
    ADC1 -> CR2 |= CR2_SWSTART;

}


uint32_t adc_read(void){
	/**wait for conversion to be complete**/
    while(!(ADC1 -> SR & SR_EOC)){}


	/**read conversion result**/
    return (ADC1-> DR);
}
