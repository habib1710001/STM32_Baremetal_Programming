/*
 * adc.h
 *
 *  Created on: 16 Nov. 2022
 *      Author: Habib Ur Rahman
 */
//Header Guard
#ifndef ADC_H_

#define ADC_H_

#include "stm32f4xx.h"
#include "stdint.h"

void pa4_adc_init(void);
void start_conversion(void);
uint32_t read_adc(void);

#endif
