/*
 * dht11.c
 *
 *  Created on: Nov 23, 2021
 *      Author: kang
 *     Version: 1.0.0
 */


#include "main.h"
#include "dht11.h"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

extern void delay_us(unsigned long us);

void DHT11_processing(DHT11 *dht11)
{
	DHT11_SendOut_StartSignal();
	DHT11_DataLineInput();
	DHT11_dumi_read();

	dht11->i_Humi = DHT11_ReadData();
	dht11->d_Humi = DHT11_ReadData();
	dht11->i_Temp = DHT11_ReadData();
	dht11->d_Temp = DHT11_ReadData();

	DHT11_DataLineOutput();
	HAL_GPIO_WritePin(DHT11_PORT, DHT11_PIN, GPIO_PIN_SET);

//	printf("Humi: %d Temp: %d\n", (int)dht11->i_Humi, (int)dht11->i_Temp);
	HAL_Delay(1500);
}

uint8_t DHT11_humidity(void)
{
	DHT11 dht11;

	DHT11_processing(&dht11);
	return dht11.i_Humi;
}

uint8_t DHT11_temperature(void)
{
	DHT11 dht11;

	DHT11_processing(&dht11);
	return dht11.i_Temp;
}

void DHT11_init(void)
{
	DHT11_DataLineOutput();
	HAL_GPIO_WritePin(DHT11_PORT, DHT11_PIN, GPIO_PIN_SET);
	HAL_Delay(3000);
	return;
}

void DHT11_DataLineInput(void)
{
	GPIO_InitTypeDef GPIO_InitStructiure = {0};

	GPIO_InitStructiure.Pin = DHT11_Pin;
	GPIO_InitStructiure.Mode = GPIO_MODE_INPUT;		// Change input
	GPIO_InitStructiure.Pull = GPIO_NOPULL;

	HAL_GPIO_Init(DHT11_PORT, &GPIO_InitStructiure);
	return;
}

void DHT11_DataLineOutput(void)
{
	GPIO_InitTypeDef GPIO_InitStructiure = {0};

	GPIO_InitStructiure.Pin = DHT11_Pin;
	GPIO_InitStructiure.Mode = GPIO_MODE_OUTPUT_PP;	// Change output
	GPIO_InitStructiure.Pull = GPIO_NOPULL;
	GPIO_InitStructiure.Speed = GPIO_SPEED_FREQ_LOW;

	HAL_GPIO_Init(DHT11_PORT, &GPIO_InitStructiure);
	return;
}

void DHT11_SendOut_StartSignal(void)
{
	HAL_GPIO_WritePin(DHT11_PORT, DHT11_PIN, GPIO_PIN_RESET);
	HAL_Delay(20);

	HAL_GPIO_WritePin(DHT11_PORT, DHT11_PIN, GPIO_PIN_SET);
	delay_us(7);
	return;
}

uint8_t DHT11_ReadData(void)
{
	uint8_t rx_data = 0;

	for(int i = 0; i < 8; i++)
	{
		//when Input Data == 0
		while( 0 == HAL_GPIO_ReadPin(DHT11_PORT, DHT11_PIN) );
#if 1
		delay_us(40);
#else  // org
		delay_us(16);
#endif
		rx_data<<=1;

		//when Input Data == 1
		if(HAL_GPIO_ReadPin(DHT11_PORT, DHT11_PIN))
		{
			rx_data |= 1;
		}
		while( 1 == HAL_GPIO_ReadPin(DHT11_PORT, DHT11_PIN) );
	}
	return rx_data;
}


void DHT11_dumi_read(void)
{
	while( 1 == HAL_GPIO_ReadPin(DHT11_PORT, DHT11_PIN) );
	while( 0 == HAL_GPIO_ReadPin(DHT11_PORT, DHT11_PIN) );
	while( 1 == HAL_GPIO_ReadPin(DHT11_PORT, DHT11_PIN) );
	return;
}

