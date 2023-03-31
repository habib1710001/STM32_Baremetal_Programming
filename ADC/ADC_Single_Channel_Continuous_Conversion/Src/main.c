#include <stdio.h>
#include <stdint.h>
#include "stm32f4xx.h"
#include "adc.h"


#define MASK(X) (1 << X )


uint32_t sensor_value;
uint32_t count = 0;
volatile int i ;

int main(void){

 	pa1_adc_init();
	start_conversion();

	while(1){
		sensor_value = adc_read();
		count = count + 5 ;
		for(i = 0 ; i <= 500 ; i++)
		{

		}
   	 }
}
