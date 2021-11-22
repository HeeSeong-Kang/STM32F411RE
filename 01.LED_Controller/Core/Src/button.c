/*
 * button.c
 *
 *  Created on: Nov 22, 2021
 *      Author: kang
 */
#include "button.h"

uint8_t preState =  RELEASED;

uint8_t getButtonState(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin, uint8_t *preState)
{
	uint8_t curState = HAL_GPIO_ReadPin(GPIOx, GPIO_Pin);

	if ((curState == PRESSED) && (*preState == RELEASED))
	{
		*preState = curState;
		HAL_Delay(200);

		return 0;
	}
	else if ((curState == RELEASED) && (*preState == PRESSED))
	{
		*preState = curState;

		return 1;
	}
	return 0;
}
