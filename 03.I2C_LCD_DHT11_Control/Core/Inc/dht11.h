/*
 * dht11.h
 *
 *  Created on: Nov 23, 2021
 *      Author: kang
 *     Version: 1.0.0
 */

#ifndef INC_DHT11_H_
#define INC_DHT11_H_

#define DHT11_PIN 	GPIO_PIN_4
#define DHT11_PORT 	GPIOC

#define DATA_BIT	40

typedef struct _DHT11{
	uint8_t i_Humi;
	uint8_t d_Humi;
	uint8_t i_Temp;
	uint8_t d_Temp;
	uint8_t checkSum;
}DHT11;

void DHT11_processing(DHT11 *dht11);
uint8_t DHT11_humidity(void);
uint8_t DHT11_temperature(void);
void DHT11_init(void);
void DHT11_DataLineInput(void);
void DHT11_DataLineOutput(void);
void DHT11_SendOut_StartSignal(void);
uint8_t DHT11_ReadData(void);
void DHT11_dumi_read(void);


#endif /* INC_DHT11_H_ */
