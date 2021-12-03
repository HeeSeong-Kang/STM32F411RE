/*
 * LED.c
 *
 *  Created on: Nov 22, 2021
 *      Author: kang
 *      Version: 1.0.1
 *      		(GPIO 변경)
 */

#include "LED.h"

/* LED OFF */
void LED_ALL_OFF()
{
	HAL_GPIO_WritePin(LED_GPIO, LED_ALL_PIN, GPIO_PIN_RESET);
}

/* LED ON */
void LED_ALL_ON()
{
	HAL_GPIO_WritePin(LED_GPIO, LED_ALL_PIN, GPIO_PIN_SET);
}

/* LED Blank Right Shift */
void LED_Blank_RightShift()
{
	LED_ALL_OFF();
	HAL_GPIO_WritePin(LED_GPIO, (0x01 << led_dot), GPIO_PIN_SET);

	if (led_dot > LED_MAX)		led_dot = 0;
	else						led_dot++;
}

/* LED Blank left Shift */
void LED_Blank_LeftShift()
{
	LED_ALL_OFF();
	HAL_GPIO_WritePin(LED_GPIO, (0x80 >> led_dot), GPIO_PIN_SET);

	if (led_dot > LED_MAX)		led_dot = 0;
	else						led_dot++;
}

/* LED Fill Right Shift */
void LED_Fill_RightShift()
{
	HAL_GPIO_WritePin(LED_GPIO, (0x01 << led_dot), GPIO_PIN_SET);

	if (led_dot > LED_MAX){
		led_dot = 0;
		LED_ALL_OFF();
	}
	else	led_dot++;
}

/* LED Fill left Shift */
void LED_Fill_LeftShift()
{
	HAL_GPIO_WritePin(LED_GPIO, (0x80 >> led_dot), GPIO_PIN_SET);

	if (led_dot > LED_MAX){
		led_dot = 0;
		LED_ALL_OFF();
	}
	else	led_dot++;
}
