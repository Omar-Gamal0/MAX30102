/************************************************/
/*  Author: Omar Gamal							*/
/*  Version: V01								*/
/* 	Date: 8 August 2020							*/
/************************************************/
#ifndef _RCC_INTERFACE_H
#define _RCC_INTERFACE_H

/**************************************************          Macros          ************************************************************/

/* Bus Id */
#define RCC_AHB			  0		// AHB Id.
#define RCC_APB1		  1		// APB1 Id.
#define RCC_APB2		  2		// APB2 Id.

/* System clock switch  */
#define SW_HSI 			  0		// HSI(Internal High-Speed clock).
#define SW_HSE 			  1		// HSE(External High-Speed clock).
#define SW_PLL 			  2		// PLL(Phase-locked loop).

/* Internal High-Speed clock */

#define HSITRIM_NOTRIM	  0		// Internal high-speed clock no trimming.
#define HSITRIM_POSITIVE  1		// Internal high-speed clock trimming positive steps.
#define HSITRIM_NEGATIVE  2		// Internal high-speed clock trimming negative steps.

/*****************************/

/*External High-Speed clock */

/* Clock security system */
#define CSSON  			  1		// Clock security system enabled.
#define CSSOFF 			  0		// Clock security system disabled.

/* External high-speed clock bypass */
#define HSEBYP_ON	  	  1		// External high-speed clock bypass enabled.
#define HSEBYP_OFF		  0		// External high-speed clock bypass disabled.

/*****************************/

/* Phase-locked loop */

/* PLL entry clock source */
#define PLLSRC_HSE 		  1		// HSE oscillator clock selected as PLL input clock.
#define PLLSRC_HSI 		  0		// HSI oscillator clock / 2 selected as PLL input clock.

/* HSE divider for PLL entry */
#define PLLXTPRE_ON       1		// HSE clock divided by 2.
#define PLLXTPRE_OFF 	  0		// HSE clock not divided.

/* PLL multiplication factor */
#define PLLMUL_X2		  0		// PLL input clock x 2.
#define PLLMUL_X3		  1		// PLL input clock x 3.
#define PLLMUL_X4		  2		// PLL input clock x 4.
#define PLLMUL_X5		  3		// PLL input clock x 5.
#define PLLMUL_X6		  4		// PLL input clock x 6.
#define PLLMUL_X7		  5		// PLL input clock x 7.
#define PLLMUL_X8		  6		// PLL input clock x 8.
#define PLLMUL_X9		  7		// PLL input clock x 9.
#define PLLMUL_X10		  8		// PLL input clock x 10.
#define PLLMUL_X11		  9		// PLL input clock x 11.
#define PLLMUL_X12		  10	// PLL input clock x 12.
#define PLLMUL_X13		  11	// PLL input clock x 13.
#define PLLMUL_X14		  12	// PLL input clock x 14.
#define PLLMUL_X15		  13	// PLL input clock x 15.
#define PLLMUL_X16		  14	// PLL input clock x 16.

/*********************/

/****************************************************************************************************************************************/

/*************************************************          Functions          **********************************************************/

/****************************************************************************************************************************************/
/* RCC_voidInitSysClock --> Initializes SYSCLK, Enabling and selecting the needed SYSCLK source and selecting the value of PLL if used.	*/
/* I/P:- void (Takes the wanted values from RCC_config file).																			*/
/* O/P:- void (Initializes SYSCLK).																										*/
/****************************************************************************************************************************************/
void RCC_voidInitSysClock(void);

/******************************************************************/
/* RCC_voidEnableClock --> Enables Clock for a certain peripheral */
/* I/P:-  
	Copy_u8BusId:- Id of the bus on which the peripheral is
	Copy_u8PerId:- Id of the peripheral							  */
/* O/P:- void(Enables Clock for a certain peripheral) 			  */
/******************************************************************/
void RCC_voidEnableClock(u8 Copy_u8BusId,u8 Copy_u8PerId);

/******************************************************************/
/* RCC_voidDisableClock --> Disables Clock for a certain peripheral */
/* I/P:-  
	Copy_u8BusId:- Id of the bus on which the peripheral is
	Copy_u8PerId:- Id of the peripheral							  */
/* O/P:- void(Disables Clock for a certain peripheral) 			  */
/******************************************************************/
void RCC_voidDisableClock(u8 Copy_u8BusId,u8 Copy_u8PerId);


#endif
