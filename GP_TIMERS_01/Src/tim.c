/*
 * tim.c
 *
 *  Created on: Mar 31, 2023
 *      Author: Habib Ur Rahman
 */
#include "stm32f4xx.h"



#define TIM2EN  (1U << 0)
#define CR1_CEN (1U << 0)

void tim2_1hz_init(void){
    /*Enable the Clock Access to TIM2*/
    RCC->APB1ENR |= TIM2EN;
	/*Set Pre-Scaler Value*/
    TIM2-> PSC = 1600 - 1 ;         // 16000000 / 1600 = 10000
	/*Set Auto-reload Value*/
    TIM2-> ARR = 10000 -1 ;       // 10000 / 10000 = 1
	/*Clear Counter*/
    TIM2-> CNT = 0;
	/*Enable Timer*/
    TIM2-> CR1 = CR1_CEN;
}


