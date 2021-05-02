/*
 * MAX30102_config.h
 *
 *  Created on: Apr 25, 2021
 *      Author: Omar
 */

#ifndef MAX30102_CONFIG_H_
#define MAX30102_CONFIG_H_

/*	FIFO Configuration	*/
#define MAX30102_FIFO_ROLLOVER_ENABLE_STATE		MAX30102_FIFO_ROLLOVER_ENABLE
#define MAX30102_FIFO_SAMPLING_AVERAGE			MAX30102_SAMPLEAVG_4

/*	Mode Configuration	*/
#define MAX30102_MODE_CONTROL					MAX30102_MULTILED_MODE

/*	SpO2 Configuration	*/
#define MAX30102_LED_PULSE_WIDTH				MAX30102_LED_PULSE_WIDTH_411
#define MAX30102_SPO2_SAMPLING_RATE				MAX30102_SPO2_SAMPLING_RATE_200
#define MAX30102_ADC_FULL_SCALE					MAX30102_ADC_FULL_SCALE_16384


/*	LED pulse amplitude Configuration	*/
/*
 * Values represents how many times of 0.2mA should the LED current value be Ex: to set current to be 6.2mA
 * we should write 0x1F(which equals 31)  as 31*.2 = 6.2
 */
#define MAX30102_LED1_PULSE_AMPLITUDE			0x1F
#define MAX30102_LED2_PULSE_AMPLITUDE			0x1F

/*	Multi-LED Mode Control Configuration	*/
#define MAX30102_SLOT1					MAX30102_LED1
#define MAX30102_SLOT2					MAX30102_LED2

#endif /* MAX30102_CONFIG_H_ */
