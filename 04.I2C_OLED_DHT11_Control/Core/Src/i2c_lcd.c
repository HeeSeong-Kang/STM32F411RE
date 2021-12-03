/*
 * i2c_lcd.c
 *
 *  Created on: Nov 22, 2021
 *      Author: kang
 *      Version: 1.0.0
 */

#include "main.h"
#include "i2c_lcd.h"
#include "stm32f4xx_hal.h"

extern I2C_HandleTypeDef hi2c1;

/* i2c lcd test main */
void i2c_lcd_main(void)
{
	uint8_t value=0;
	I2C_LCD1602_init();

	while(1){
		move_cursor(0,0);
		lcd_string("mamamamamam");
		move_cursor(1,0);
		lcd_data(value + '0');
		value++;
		if(value>9)value=0;
		HAL_Delay(500);
	}
}

void I2C_LCD1602_init()
{
	wirte4bit(0x30, 0);
	HAL_Delay(5);

	wirte4bit(0x30, 0);
	HAL_Delay(1);

	wirte4bit(0x30, 0);
	HAL_Delay(1);

	wirte4bit(0x20, 0);

	lcd_command(LCD_INIT_FUNCTION, 0);	// Function Set 4-bit mode
	lcd_command(LCD_INIT_DISPLAYON, 0);	// Display on
	lcd_command(LCD_INIT_CLEAR, 0);		// Display clear
	lcd_command(LCD_INIT_ENTRYMODE, 0);	// Entry mode set

	HAL_Delay(2);
}

void lcd_command(uint8_t data, uint8_t RS)
{
	uint8_t highBit, lowBit;

	highBit = 0xf0 & data;		// Data high 4bit
	lowBit = 0xf0 & (data<<4);	// Data low 4bit

	wirte4bit(highBit, RS);
	wirte4bit(lowBit, RS);
}

void wirte4bit(uint8_t data, uint8_t RS)
{
	uint8_t buff[2];

	// Register bit
	if(RS)	RS = LCD_RS;
	else	RS = 0x00;

	buff[0] = 0x04 | RS | LCD_BACKLIGHT | data;
	buff[1] = 0x00 | RS | LCD_BACKLIGHT | data;
	while(HAL_I2C_Master_Transmit(&hi2c1, LCD_ADDRESS, buff, 2, 100) != HAL_OK);
}

void lcd_X_Y_string_data(uint8_t row, uint8_t column, uint8_t *str)
{
	move_cursor(row, column);
	lcd_string(str);
}

void lcd_data(uint8_t value)
{
	lcd_command(value + '0', 1);
}

void lcd_string(uint8_t *str)
{
	while(*str)lcd_command(*str++, 1);
}

void move_cursor(uint8_t row, uint8_t column)
{
	lcd_command(0x80 | row<<6 | column, 0);
	return;
}
