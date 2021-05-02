/*
 * MAX30102_program.c
 *
 *  Created on: Apr 25, 2021
 *      Author: Omar
 */


#include "BIT_MATH.h"
#include "STD_TYPES.h"

#include "MAX30102_interface.h"
#include "MAX30102_config.h"
#include "MAX30102_private.h"
#include "I2C_interface.h"

/*
 * Pseudo-Code Example of Reading Data from FIFO
 * First transaction: Get the FIFO_WR_PTR:
 * START;
 * Send device address + write mode
 * Send address of FIFO_WR_PTR;
 * REPEATED_START;
 * Send device address + read mode
 * Read FIFO_WR_PTR;
 * STOP;
 */

static void Fill_IR_Red(u8 * Readings, u32 * IR, u32 * Red)
{
	u8 IR_Counter=0;
	u8 Red_Counter=0;
	for(u8 i = 0; i<192; i++)
	{
		if((i%3) == (i%6))
		{
			Red[Red_Counter] |= (Readings[i] << ((2-(i%3))*8));
			//Red[Red_Counter] = Readings[i];
			if(i==0)
				continue;
			if((i+1)%3 == 0)
				Red_Counter++;

		}else{
			IR[IR_Counter] |= (Readings[i] << ((2-(i%3))*8));
			//IR[IR_Counter] = Readings[i];
			if(i==0)
				continue;
			if((i+1)%3 == 0)
				IR_Counter++;
		}
	}
}

void MAX30102_voidWriteRegister(u8 Cpy_u8Register, u8 Cpy_u8Value)
{
	u8 Temp_pu8Buffer[2] = {Cpy_u8Register, Cpy_u8Value};
	I2C_voidMasterSendData(I2C1, Temp_pu8Buffer, 2, MAX30102_SLAVE_ADDRESS, I2C_NO_REPEAT_S);
}

void MAX30102_voidWriteSeqRegisters(u8 Cpy_u8StartRegister, u8 * p_u8Values, u8 Cpy_u8NoOfVals)
{
	u8 Temp_pu8Buffer[10];
	Temp_pu8Buffer[0] = Cpy_u8StartRegister;
	for(u8 i = 0; i < Cpy_u8NoOfVals; i++)
	{
		Temp_pu8Buffer[i+1] = p_u8Values[i];
	}
	I2C_voidMasterSendData(I2C1, Temp_pu8Buffer, (Cpy_u8NoOfVals+1), MAX30102_SLAVE_ADDRESS, I2C_NO_REPEAT_S);
}

u8 MAX30102_u8ReadRegister(u8 Cpy_u8Register)
{
	u8 Temp_u8RegVal;
	I2C_voidMasterSendData(I2C1, &Cpy_u8Register, 1, MAX30102_SLAVE_ADDRESS, I2C_REPEAT_S);
	I2C_voidMasterReceiveData(I2C1, &Temp_u8RegVal, 1, MAX30102_SLAVE_ADDRESS);
	return Temp_u8RegVal;
}

void MAX30102_voidReadSeqRegisters(u8 Cpy_u8StartRegister, u8 * p_u8Values, u8 Cpy_u8NoOfVals)
{
	I2C_voidMasterSendData(I2C1, &Cpy_u8StartRegister, 1, MAX30102_SLAVE_ADDRESS, I2C_REPEAT_S);
	I2C_voidMasterReceiveData(I2C1, p_u8Values, Cpy_u8NoOfVals, MAX30102_SLAVE_ADDRESS);
}

void MAX30102_voidGetReadings(u32 * p_u8IR_RxBuffer, u32 * p_u8Red_RxBuffer)
{
	u8 Readings[192];

	MAX30102_voidWriteRegister(MAX30102_FIFO_READ_PTR, 0);

	for(int i = 0; i< 10; i++)
	{
		__asm("NOP");
	}

	MAX30102_voidReadSeqRegisters(MAX30102_FIFO_DATA, Readings, 192);
	Fill_IR_Red(Readings, p_u8IR_RxBuffer, p_u8Red_RxBuffer);



}

void MAX30102_voidInit(void)
{
	u8 Temp_u8RegVal[3];
	Temp_u8RegVal[0] = (MAX30102_FIFO_ROLLOVER_ENABLE_STATE << MAX30102_FIFO_CONFIG_FIFO_ROLLOVER_EN) | ((0x07 & MAX30102_FIFO_SAMPLING_AVERAGE) << MAX30102_FIFO_CONFIG_SMP_AVE);
	Temp_u8RegVal[1] = (0x7 & MAX30102_MODE_CONTROL) << MAX30102_MODE_CONFIG_MODE;
	Temp_u8RegVal[2] = ((0x3 & MAX30102_LED_PULSE_WIDTH) << MAX30102_SPO2_CONFIG_LED_PW) | ((0x7 & MAX30102_SPO2_SAMPLING_RATE) << MAX30102_SPO2_CONFIG_SPO2_SR) | ((0x3 & MAX30102_ADC_FULL_SCALE) << MAX30102_SPO2_CONFIG_SPO2_ADC_RGE);
	MAX30102_voidWriteSeqRegisters(MAX30102_FIFO_CONFIG, Temp_u8RegVal, 3);

	for(int i = 0; i< 10; i++)
	{
		__asm("NOP");
	}

	Temp_u8RegVal[0] = MAX30102_LED1_PULSE_AMPLITUDE;
	Temp_u8RegVal[1] = MAX30102_LED2_PULSE_AMPLITUDE;
	MAX30102_voidWriteSeqRegisters(MAX30102_LED1_PULSE_AMP, Temp_u8RegVal, 2);

	for(int i = 0; i< 10; i++)
	{
		__asm("NOP");
	}

	Temp_u8RegVal[0] = ((0x3 & MAX30102_SLOT1) << MAX30102_MULTILED_CONFIG1__SLOT1) | ((0x7 & MAX30102_SLOT2) << MAX30102_MULTILED_CONFIG1__SLOT2);
	MAX30102_voidWriteRegister(MAX30102_MULTILED_CONFIG1, Temp_u8RegVal[0]);

	for(int i = 0; i< 10; i++)
	{
		__asm("NOP");
	}

	MAX30102_voidReadSeqRegisters(MAX30102_FIFO_CONFIG, Temp_u8RegVal, 3);
	MAX30102_voidReadSeqRegisters(MAX30102_LED1_PULSE_AMP, Temp_u8RegVal, 2);
	Temp_u8RegVal[0] = MAX30102_u8ReadRegister(MAX30102_MULTILED_CONFIG1);

}

/*
void MAX30102_voidInit(void)
{
	u8 Temp_u8RegVal;
	Temp_u8RegVal = (MAX30102_FIFO_ROLLOVER_ENABLE_STATE << MAX30102_FIFO_CONFIG_FIFO_ROLLOVER_EN) | ((0x07 & MAX30102_FIFO_SAMPLING_AVERAGE) << MAX30102_FIFO_CONFIG_SMP_AVE);
	MAX30102_voidWriteRegister(MAX30102_FIFO_CONFIG, Temp_u8RegVal);
	Temp_u8RegVal = (0x7 & MAX30102_MODE_CONTROL) << MAX30102_MODE_CONFIG_MODE;
	MAX30102_voidWriteRegister(MAX30102_MODE_CONFIG, Temp_u8RegVal);
	Temp_u8RegVal = ((0x3 & MAX30102_LED_PULSE_WIDTH) << MAX30102_SPO2_CONFIG_LED_PW) | ((0x7 & MAX30102_SPO2_SAMPLING_RATE) << MAX30102_SPO2_CONFIG_SPO2_SR) | ((0x3 & MAX30102_ADC_FULL_SCALE) << MAX30102_SPO2_CONFIG_SPO2_ADC_RGE);
	MAX30102_voidWriteRegister(MAX30102_SPO2_CONFIG, Temp_u8RegVal);

	MAX30102_voidWriteRegister(MAX30102_LED1_PULSE_AMP, MAX30102_LED1_PULSE_AMPLITUDE);
	MAX30102_voidWriteRegister(MAX30102_LED2_PULSE_AMP, MAX30102_LED2_PULSE_AMPLITUDE);

	Temp_u8RegVal = ((0x3 & MAX30102_SLOT1) << MAX30102_MULTILED_CONFIG1__SLOT1) | ((0x7 & MAX30102_SLOT2) << MAX30102_MULTILED_CONFIG1__SLOT2);
	MAX30102_voidWriteRegister(MAX30102_MULTILED_CONFIG1, Temp_u8RegVal);

	for(int i = 0; i< 300000; i++)
	{
		__asm("NOP");
	}

	Temp_u8RegVal = MAX30102_u8ReadRegister(MAX30102_FIFO_READ_PTR);

	for(u8 x = 0; x < 25; x++)
	{

		Temp_u8RegVal = MAX30102_u8ReadRegister(MAX30102_FIFO_WRIT_EPTR);

		for(int i = 0; i< 30000; i++)
		{
			__asm("NOP");
		}

	}
}
*/
