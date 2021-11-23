/*
 * i2c_lcd.h
 *
 *  Created on: Nov 22, 2021
 *      Author: kang
 */

#ifndef INC_I2C_LCD_H_
#define INC_I2C_LCD_H_

// COMMAND
#define LCD_SCREENCLEAR 	0x01
#define LCD_CURSORRETURN 	0x02
#define LCD_INPUTSET 		0x04
#define LCD_DISPLAYSWITCH	0x08
#define LCD_CURSORSHIFT		0x10
#define LCD_FUNCTIONSET 	0x20
#define LCD_CGRAMADSET 		0x40
#define LCD_DDRAMADSET 		0x80

// INPUT SET
#define LCD_INPUTSETRIGHT		0x00
#define LCD_INPUTSETLEFT		0x01
#define LCD_INPUTSETINCREMENT	0x02
#define LCD_INPUTSETDEINCREMENT	0x00

// DISPLAY ON/OFF CONTROL
#define LCD_DISPLAYON			0x04
#define LCD_DISPLAYOFF			0x00
#define LCD_DISPLAYCURSORON		0x02
#define LCD_DISPLAYCURSOROFF	0x00
#define LCD_DISPLAYBLINKON		0x01
#define LCD_DISPLAYBLINKOFF		0x00

// LCD_DISPLAYSWITCH
#define LCD_DISPLAYSHIFTMODE	0x08
#define LCD_CURSORSHIFTMODE		0x00
#define LCD_RIGHTSHIFT			0x04
#define LCD_LEFTSHIFT			0x00

// FUNCTION SET
#define LCD_8BITMODE		0x10
#define LCD_4BITMODE		0x00
#define LCD_2LINE			0x08
#define LCD_1LINE			0x00
#define LCD_5x10STYLE		0x04
#define LCD_5x7STYLE		0x00

// DISPLAY BACKLIGHT
#define LCD_BACKLIGHT		0x08

// SLAVE ADDRESS
#define LCD_ADDRESS			(0x27<<1)

#define LCD_EN		0x04	// Enable bit
#define LCD_RW		0x02	// Read/Write bit
#define LCD_RS		0x01	// Register Select bit

// INSTRUCTION SET
#define LCD_INIT_FUNCTION	LCD_FUNCTIONSET|LCD_4BITMODE|LCD_2LINE|LCD_5x7STYLE
#define LCD_INIT_DISPLAYOFF	LCD_DISPLAYSWITCH|LCD_DISPLAYOFF|LCD_DISPLAYCURSOROFF|LCD_DISPLAYBLINKOFF
#define LCD_INIT_DISPLAYON	LCD_DISPLAYSWITCH|LCD_DISPLAYON|LCD_DISPLAYCURSOROFF|LCD_DISPLAYBLINKOFF
#define LCD_INIT_CLEAR		LCD_SCREENCLEAR
#define LCD_INIT_ENTRYMODE	LCD_INPUTSET|LCD_INPUTSETINCREMENT


void i2c_lcd_main(void);
void I2C_LCD1602_init();
void lcd_command(uint8_t data, uint8_t RS);
void wirte4bit(uint8_t data, uint8_t RS);
void lcd_X_Y_string_data(uint8_t row, uint8_t column, uint8_t *str);
void lcd_data(uint8_t value);
void lcd_string(uint8_t *str);
void move_cursor(uint8_t row, uint8_t column);


#endif /* INC_I2C_LCD_H_ */
