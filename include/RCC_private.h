/************************************************/
/*  Auther: Omar Gamal							*/
/*  Version: V02								*/
/* 	Date: 11 August 2020						*/
/************************************************/
#ifndef _RCC_PRIVATE_H
#define _RCC_PRIVATE_H


/* Register Definition */

#define RCC_CR						*((volatile u32*)0x40021000)
#define RCC_CFGR 					*((volatile u32*)0x40021004)
#define RCC_CIR 					*((volatile u32*)0x40021008)
#define RCC_APB2RSTR 				*((volatile u32*)0x4002100c)
#define RCC_APB1RSTR 				*((volatile u32*)0x40021010)
#define RCC_AHBENR 					*((volatile u32*)0x40021014)
#define RCC_APB2ENR 				*((volatile u32*)0x40021018)
#define RCC_APB1ENR 				*((volatile u32*)0x4002101c)
#define RCC_BDCR 					*((volatile u32*)0x40021020)
#define RCC_CSR 					*((volatile u32*)0x40021024)

/***********************/

/* CLOCKS PRESCALAR MACROS */

/* AHB PRESCALAR */

#define RCC_AHB_PRESCALAR_DIV_NO 	0x0
#define RCC_AHB_PRESCALAR_DIV_2 	0x8
#define RCC_AHB_PRESCALAR_DIV_4 	0x9
#define RCC_AHB_PRESCALAR_DIV_8 	0xA
#define RCC_AHB_PRESCALAR_DIV_16 	0xB
#define RCC_AHB_PRESCALAR_DIV_64 	0xC
#define RCC_AHB_PRESCALAR_DIV_128 	0xD
#define RCC_AHB_PRESCALAR_DIV_256 	0xE
#define RCC_AHB_PRESCALAR_DIV_512 	0xF

/*****************/

/* APB1 PRESCALAR */

#define RCC_APB1_PRESCALAR_DIV_NO 	0x0
#define RCC_APB1_PRESCALAR_DIV_2 	0x4
#define RCC_APB1_PRESCALAR_DIV_4 	0x5
#define RCC_APB1_PRESCALAR_DIV_8 	0x6
#define RCC_APB1_PRESCALAR_DIV_16 	0x7

/*****************/

/* APB2 PRESCALAR */

#define RCC_APB2_PRESCALAR_DIV_NO 	0x0
#define RCC_APB2_PRESCALAR_DIV_2 	0x4
#define RCC_APB2_PRESCALAR_DIV_4 	0x5
#define RCC_APB2_PRESCALAR_DIV_8 	0x6
#define RCC_APB2_PRESCALAR_DIV_16 	0x7

/*****************/

/***************************/

/* Private functions */

/***************************************************/
/* HSITRIM_RESET --> Resets HSITRIM value to 10000 */
/* I/P:- void                                      */
/* O/P:- void (Resets HSITRIM value)			   */
/***************************************************/
void HSITRIM_RESET(void);

/***************************************************/
/* HSITRIM_CLR --> Clears HSITRIM value to 00000   */
/* I/P:- void                                      */
/* O/P:- void (Clears HSITRIM value)			   */
/***************************************************/
void HSITRIM_CLR(void);

#endif