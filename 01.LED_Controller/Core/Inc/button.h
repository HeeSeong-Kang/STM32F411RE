/*
 * button.h
 *
 *  Created on: Nov 22, 2021
 *      Author: kang
 */

#ifndef INC_BUTTON_H_
#define INC_BUTTON_H_

#include "main.h"

#define PUSHBUTTON_PORT		GPIOC
#define	PUSHBUTTON1 		GPIO_PIN_0
#define PUSHBUTTON2 		GPIO_PIN_1
#define PUSHBUTTON3 		GPIO_PIN_2

#define PRESSED				0
#define RELEASED			1

extern uint8_t preState;

uint8_t getButtonState(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin, uint8_t *preState);

#endif /* INC_BUTTON_H_ */
