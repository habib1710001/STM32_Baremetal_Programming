#include "stm32f4xx.h"
#include "tim.h"

#define GPIOAEN (1U <<0)
#define PIN5   (1U<<5 )
#define LED_PIN PIN5

int main(void)
{
    RCC->AHB1ENR |= GPIOAEN ;
    GPIOA-> MODER |= (1U << 10);
    GPIOA -> MODER &= ~(1U << 11);

    tim2_1hz_init();

    while(1){

    	/*Wait for 1 Second*/
        while(!((TIM2->SR) & SR_UIF)){}

        /*Clear the UIF Status*/
        //This bit is set by hardware on an update event, It is cleared by software
        TIM2 -> SR &= ~SR_UIF;
    	GPIOA -> ODR ^= LED_PIN ;
	 }
}
