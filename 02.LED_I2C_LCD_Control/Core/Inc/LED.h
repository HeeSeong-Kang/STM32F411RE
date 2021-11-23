/*
 * LED.h
 *
 *  Created on: Nov 22, 2021
 *      Author: kang
 */

#ifndef INC_LED_H_
#define INC_LED_H_

#include "main.h"


#define LED_GPIO 		GPIOB

#define LED0_Pin 		GPIO_PIN_0
#define LED1_Pin		GPIO_PIN_1
#define LED2_Pin 		GPIO_PIN_2
#define LED3_Pin 		GPIO_PIN_3
#define LED4_Pin 		GPIO_PIN_4
#define LED5_Pin 		GPIO_PIN_5
#define LED6_Pin 		GPIO_PIN_6
#define LED7_Pin 		GPIO_PIN_7

#define LED_ALL_PIN		LED0_Pin|LED1_Pin|LED2_Pin|LED3_Pin|LED4_Pin|LED5_Pin|LED6_Pin|LED7_Pin
#define LED_ODD_PIN		LED0_Pin|LED2_Pin|LED4_Pin|LED6_Pin
#define LED_EVEN_PIN	LED1_Pin|LED3_Pin|LED5_Pin|LED7_Pin

#define LED_MAX			7

static uint8_t led_dot = 0;

void LED_ALL_OFF();
void LED_ALL_ON();
void LED_Blank_RightShift();
void LED_Blank_LeftShift();
void LED_Fill_RightShift();
void LED_Fill_LeftShift();

#endif /* INC_LED_H_ */
