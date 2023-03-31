/*
 * TimeFunctions.c
 *
 *  Created on: Dec 12, 2022
 *      Author: Habib
 */


#include "stm32f4xx.h"

#include "TimeFunctions.h"

#define SYSTICK_LOAD_VAL 16000   //As the default clock frequency is 16 mHz
#define CTRL_ENABLE    (1U << 0)
#define CTRL_CLOCK_SOURCE (1U << 3)
#define CTRL_COUNTFLAG    (1U<< 16)





void systickDelayMs(int delay){
     /**Reload with the number of clocks per millisecond**/
     SysTick -> LOAD = SYSTICK_LOAD_VAL;

     /**Clearing the current value**/
     SysTick -> VAL = 0;

     /**Configuring the Systick Timer**/
     SysTick -> CTRL |= (CTRL_ENABLE | CTRL_CLOCK_SOURCE);

     //control variable
     int i;

     for (i=0 ; i < delay ; i++){
    	 while((SysTick -> CTRL & CTRL_COUNTFLAG) == 0)
    	   {
    		 //Count flag is HIGH when the counting done
           }
     }
}
