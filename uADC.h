/*
 * uADC.h
 *
 *  Created on: Dec 23, 2022
 *      Author: @Alixahedi
 */

#ifndef INC_UADC_H_
#define INC_UADC_H_

#include "main.h"

/* ------------------------------------------------------------------ */

#define MultiChannel 1

/* ------------------------------------------------------------------ */

uint16_t analogRead(ADC_HandleTypeDef* hadc, uint32_t Channel);
float voltageRead(ADC_HandleTypeDef* hadc, uint32_t Channel);

#endif /* INC_UADC_H_ */
