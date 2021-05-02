/*
 * MAX30102_private.h
 *
 *  Created on: Apr 25, 2021
 *      Author: Omar
 */

#ifndef MAX30102_PRIVATE_H_
#define MAX30102_PRIVATE_H_


/*  Slave Address	*/
#define MAX30102_SLAVE_ADDRESS		0x57

/*  Status Registers	*/
#define MAX30102_INT_STAT1 			0x00
#define MAX30102_INT_STAT2 			0x01
#define MAX30102_INT_ENABLE1 		0x02
#define MAX30102_INT_ENABLE2 		0x03

/*  FIFO Registers	*/
#define MAX30102_FIFO_WRIT_EPTR  	0x04
#define MAX30102_FIFO_OVER_FLOW  	0x05
#define MAX30102_FIFO_READ_PTR  	0x06
#define MAX30102_FIFO_DATA 			0x07

/*  Configuration Registers	*/
#define MAX30102_FIFO_CONFIG  		0x08
#define MAX30102_MODE_CONFIG  		0x09
#define MAX30102_SPO2_CONFIG  		0x0A
#define MAX30102_LED1_PULSE_AMP  	0x0C
#define MAX30102_LED2_PULSE_AMP  	0x0D
#define MAX30102_MULTILED_CONFIG1  	0x11
#define MAX30102_MULTILED_CONFIG2  	0x12

/*	Die Temperature Registers	*/
#define MAX30102_DIE_TEMP_INT  		0x1F
#define MAX30102_DIE_TEMP_FRAC  	0x20
#define MAX30102_DIE_TEMP_CONFIG  	0x21

/*	Part ID Registers	*/
#define MAX30102_REVISION_ID  		0xFE
#define MAX30102_PART_ID  			0xFF    // Should always be 0x15.


/* Interrupt Status 1 (Same for Interrupt Enable 1 except for PWR_RDY) Bits Macros (or starting bits for multi-bits areas) */
#define MAX30102_INT_STAT1_PWR_RDY						0
#define MAX30102_INT_STAT1_ALC_OVF						5
#define MAX30102_INT_STAT1_PPG_RDY						6
#define MAX30102_INT_STAT1_A_FULL						7

/* Interrupt Status 2 (Same for Interrupt Enable 2) Bits Macros (or starting bits for multi-bits areas) */
#define MAX30102_INT_STAT2_DIE_TEMP_RDY					1

/* FIFO Configuration Bits Macros (or starting bits for multi-bits areas) */
#define MAX30102_FIFO_CONFIG_FIFO_A_FULL				0
#define MAX30102_FIFO_CONFIG_FIFO_ROLLOVER_EN			4
#define MAX30102_FIFO_CONFIG_SMP_AVE					5

/* Mode Configuration Bits Macros (or starting bits for multi-bits areas) */
#define MAX30102_MODE_CONFIG_MODE						0
#define MAX30102_MODE_CONFIG_RESET						6
#define MAX30102_MODE_CONFIG_SHDN						7

/* SpO2 Configuration Bits Macros (or starting bits for multi-bits areas) */
#define MAX30102_SPO2_CONFIG_LED_PW						0
#define MAX30102_SPO2_CONFIG_SPO2_SR					2
#define MAX30102_SPO2_CONFIG_SPO2_ADC_RGE				5

/* Multi-LED Mode Control Register Bits Macros (or starting bits for multi-bits areas) */
#define MAX30102_MULTILED_CONFIG1__SLOT1				0
#define MAX30102_MULTILED_CONFIG1__SLOT2				4

#endif /* MAX30102_PRIVATE_H_ */
