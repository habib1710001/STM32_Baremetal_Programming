/*
 * TIMOCM.c
 *
 *  Created on: Apr 2, 2023
 *      Author: Habib Ur Rahman
 */


#include "stm32f4xx.h"



#define TIM2EN  (1U << 0)
#define CR1_CEN (1U << 0)
#define OC_TOGGLE ((1U<<4) | (1U<<5))
#define CCER_CC1E (1U<<0)


#define GPIOAEN (1U<<0)
#define AFR5_TIM (1U<<20)

void tim2_pa5_1hz_init(void){

	/*Enable the clock for PA5*/
	RCC -> AHB1ENR |= GPIOAEN;

	/*Enable the alternative function mode*/
	GPIOA -> MODER |= (1U << 11);
	GPIOA -> MODER |= ~(1U << 10);

	/*Set the alternative function type (AF01)*/
	GPIOA -> AFR[0] |= AFR5_TIM;   //Alternate function low register


    /*Enable the Clock Access to TIM2*/
    RCC->APB1ENR |= TIM2EN;
	/*Set Pre-Scaler Value*/
    TIM2-> PSC = 1600 - 1 ;         // 16000000 / 1600 = 10000
	/*Set Auto-reload Value*/
    TIM2-> ARR = 10000 -1 ;       // 10000 / 10000 = 1

    /*Set output compare toggle mode*/
    TIM2 -> CCMR1 |= OC_TOGGLE ;

    /*Enable tim2 ch1 in compare mode*/
    TIM2 -> CCER |= CCER_CC1E;
	/*Clear Counter*/
    TIM2-> CNT = 0;
	/*Enable Timer*/
    TIM2-> CR1 = CR1_CEN;
}
