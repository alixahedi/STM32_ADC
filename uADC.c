/*
 * uADC.c
 *
 *  Created on: Dec 23, 2022
 *      Author: @Alixahedi
 */

#include "uADC.h"

#ifdef MultiChannel
static void AdcChannelSelect(ADC_HandleTypeDef* hadc,uint32_t Channel) {
	ADC_ChannelConfTypeDef sConfig = { 0 };
	sConfig.Channel = Channel;
	sConfig.Rank = 1;
	sConfig.SamplingTime = 0x00000000U;
	if (HAL_ADC_ConfigChannel(hadc, &sConfig) != HAL_OK) {
		Error_Handler();
	}

}
#endif

uint16_t analogRead(ADC_HandleTypeDef* hadc, uint32_t Channel) {
	int ret;
#ifdef MultiChannel
	AdcChannelSelect(hadc, Channel);
#endif
	HAL_ADC_Start(hadc);
	HAL_ADC_PollForConversion(hadc, HAL_MAX_DELAY);
	ret = HAL_ADC_GetValue(hadc);
	return ret;
}

float voltageRead(ADC_HandleTypeDef* hadc, uint32_t Channel) {
	int val;
	float ret;
	val = analogRead(hadc, Channel);
	ret = (float)(val * 3.3) / (4095);
	return ret;
}

