/*
 * main.c
 *
 *  Created on: Apr 14, 2021
 *      Author: Omar
 */

#include "BIT_MATH.h"
#include "STD_TYPES.h"
#include "RCC_interface.h"
#include "GPIO_interface.h"
#include "I2C_interface.h"
#include "MAX30102_interface.h"

#define SLAVE_ADD		0x68

u8 data[32];

void I2C1_PinsInit(void)
{
	/* configuring B6 == SCL & B7 == SDA as AF open drain */
	GPIO_voidSetPinMode(GPIO_U8_PORTB, GPIO_U8_PIN6, GPIO_U8_OUTPUT_MODE_AF_OD, GPIO_U8_PIN_MODE_OUTPUT_MAX2MHZ);
	GPIO_voidSetPinMode(GPIO_U8_PORTB, GPIO_U8_PIN7, GPIO_U8_OUTPUT_MODE_AF_OD, GPIO_U8_PIN_MODE_OUTPUT_MAX2MHZ);
}

void I2C1_Init(void)
{
	/* Enabling I2C1 clock */
	RCC_voidEnableClock(RCC_APB1, 21);

	/* Enabling I2C1 */
	I2C_voidPeripheralControl(I2C1, I2C_ENABLE);

	/* Initializing I2C1 */
	I2C_voidInit(I2C1);

}

int main(void)
{
	u32 IR_Readings[32]={0};
	u32 Red_Readings[32]={0};

	RCC_voidInitSysClock();
	RCC_voidEnableClock(RCC_APB2, 3);
	I2C1_PinsInit();
	I2C1_Init();

	MAX30102_voidInit();

	MAX30102_voidGetReadings(IR_Readings, Red_Readings);
	RCC_voidInitSysClock();
	while(1)
	{
	}





	return 0;
}
