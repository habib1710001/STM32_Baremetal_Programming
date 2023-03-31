#include "stm32f4xx.h"
#include "stdint.h"
#include "adc.h"
#include "TimeFunctions.h"
#include "RCFilter.h"

uint32_t sensorValue;
float filteredSensorValue;
RCFilter sensor1;

int main(void){

	pa4_adc_init();
	start_conversion();
	RCFilter_Init(&sensor1 , 50.0f , 0.01f);

	while(1){
	    sensorValue = read_adc();
	    filteredSensorValue = RCFilter_Update(&sensor1, (float)sensorValue);
	    systickDelayMs(10);
   	 }
}
