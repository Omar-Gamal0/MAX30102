/*
 * MAX30102_interface.h
 *
 *  Created on: Apr 25, 2021
 *      Author: Omar
 */

#ifndef MAX30102_INTERFACE_H_
#define MAX30102_INTERFACE_H_

/*	FIFO Configuration options	*/

/*  Sampling Average Options	*/
#define MAX30102_SAMPLEAVG_1			0
#define MAX30102_SAMPLEAVG_2			1
#define MAX30102_SAMPLEAVG_4			2
#define MAX30102_SAMPLEAVG_8			3
#define MAX30102_SAMPLEAVG_16			4
#define MAX30102_SAMPLEAVG_32			5

/*  FIFO Roll over options	*/
#define MAX30102_FIFO_ROLLOVER_ENABLE	1
#define MAX30102_FIFO_ROLLOVER_DISABLE	0

/********************************/



/*	Mode Control Options	*/
#define MAX30102_HEART_RATE_MODE		2
#define MAX30102_SPO2_MODE				3
#define MAX30102_MULTILED_MODE			7
/********************************/


/*	SpO2 Configuration options	*/

/*  LED Pulse Width options	*/
#define MAX30102_LED_PULSE_WIDTH_69		0		/*	ADC RESOLUTION: 15 bits	*/
#define MAX30102_LED_PULSE_WIDTH_118	1		/*	ADC RESOLUTION: 16 bits	*/
#define MAX30102_LED_PULSE_WIDTH_215	2		/*	ADC RESOLUTION: 17 bits	*/
#define MAX30102_LED_PULSE_WIDTH_411	3		/*	ADC RESOLUTION: 18 bits	*/

/*  SpO2 Sample Rate options	*/
#define MAX30102_SPO2_SAMPLING_RATE_50		0
#define MAX30102_SPO2_SAMPLING_RATE_100		1
#define MAX30102_SPO2_SAMPLING_RATE_200		2
#define MAX30102_SPO2_SAMPLING_RATE_400		3
#define MAX30102_SPO2_SAMPLING_RATE_800		4
#define MAX30102_SPO2_SAMPLING_RATE_1000	5
#define MAX30102_SPO2_SAMPLING_RATE_1600	6
#define MAX30102_SPO2_SAMPLING_RATE_3200	7


/*  ADC full scale range options	*/
#define MAX30102_ADC_FULL_SCALE_2048	0
#define MAX30102_ADC_FULL_SCALE_4096	1
#define MAX30102_ADC_FULL_SCALE_8192	2
#define MAX30102_ADC_FULL_SCALE_16384	3

/********************************/

/*	Multi-LED Mode Control options	*/
#define MAX30102_LED1					1			/*	RED LED	*/
#define MAX30102_LED2					2			/*	IR  LED	*/
/****************************/


void MAX30102_voidWriteRegister(u8 Cpy_u8Register, u8 Cpy_u8Value);
void MAX30102_voidWriteSeqRegisters(u8 Cpy_u8StartRegister, u8 * p_u8Values, u8 Cpy_u8NoOfVals);
u8 MAX30102_u8ReadRegister(u8 Cpy_u8Register);
void MAX30102_voidReadSeqRegisters(u8 Cpy_u8StartRegister, u8 * p_u8Values, u8 Cpy_u8NoOfVals);
void MAX30102_voidInit(void);
void MAX30102_voidGetReadings(u32 * p_u8IR_RxBuffer, u32 * p_u8Red_RxBuffer);

u8 MAX30102_u8GetSPO2Value();
u8 MAX30102_u8GetHRValue();

#endif /* MAX30102_INTERFACE_H_ */
