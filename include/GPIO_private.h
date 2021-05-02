/************************************************/
/*  Auther: Omar Gamal							*/
/*  Version: V03								*/
/* 	Date: 19 August 2020						*/
/************************************************/

#ifndef _GPIO_PRIVATE_H
#define _GPIO_PRIVATE_H

/* Defining GPIO_PORT type */
typedef struct{
	__V	u32 			CRL;
	__V	u32 			CRH;
	__V	u32 			IDR;
	__V	u32 			ODR;
	__V	u32 			BSRR;
	__V	u32 			BRR;
	__V	u32 			LCKR;
}GPIO_Port_t;
/***************************/

/* Defining Ports Macros */
#define MGPIO_PORTA			((__V GPIO_Port_t*)0x40010800)
#define MGPIO_PORTB			((__V GPIO_Port_t*)0x40010C00)
#define MGPIO_PORTC			((__V GPIO_Port_t*)0x40011000)
/*************************/




/* Private Functions */

/*********************/

#endif

