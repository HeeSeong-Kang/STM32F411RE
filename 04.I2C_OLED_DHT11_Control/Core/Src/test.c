/*
 * test.c
 *
 *  Created on: Nov 24, 2021
 *      Author: kang
 */

#include "main.h"
#include "button.h"
#include "LED.h"
#include "i2c_lcd.h"
#include "dht11.h"
#include "ssd1306.h"
#include "fonts.h"

#include <stdio.h>


void test_processing()
{
	uint8_t temp, humi;
	char buffer[20];

	temp = DHT11_temperature();
	humi = DHT11_humidity();

	sprintf(buffer, "T:%dC   H:%d%%", temp, humi);
	lcd_X_Y_string_data(0, 0, buffer);

	sprintf(buffer, "T:%dC H:%d%%", temp, humi);
	ssd1306_SetCursor(0, 0);
	ssd1306_WriteString(buffer, Font_11x18, White);
	ssd1306_UpdateScreen();
}
