/************************************************/
/*  Auther: Omar Gamal							*/
/*  Version: V02								*/
/* 	Date: 11 August 2020						*/
/************************************************/
#ifndef _RCC_CONFIG_H
#define _RCC_CONFIG_H

#define SW_VAL 					SW_HSI 				// Selects the wanted SYSCLK source. 

/* Internal High-Speed clock config */

#define HSITRIM_SIGN		  	HSITRIM_NOTRIM  	// Selects the sign of Internal high-speed clock trimming.
#define HSITRIM_STEPS 		  	0					// Writes Number of steps of Internal high-speed clock trimming.

/************************************/

/* External High-Speed clock config */

#define CSSON_VAL 				CSSON				// Selects the state of Clock security system.
#define HSEBYP_VAL				HSEBYP_OFF  		// Selects the state of external high-speed clock bypass.

/************************************/

/* Phase-locked loop config */

#define PLLSRC_VAL 				PLLSRC_HSI			// Selects the PLL entry clock source.
#define PLLXTPRE_VAL			PLLXTPRE_OFF		// Selects the state of HSE divider for PLL entry.
#define PLLMUL_VAL 				PLLMUL_X2   		// Selects the value of PLL multiplication factor.

/****************************/

/* Clocks prescalars */

/* Available options for AHB Clock prescalar are:-
	RCC_AHB_PRESCALAR_DIV_NO 	
	RCC_AHB_PRESCALAR_DIV_2 	
	RCC_AHB_PRESCALAR_DIV_4 	
	RCC_AHB_PRESCALAR_DIV_2 	
	RCC_AHB_PRESCALAR_DIV_2 	
	RCC_AHB_PRESCALAR_DIV_2 	
	RCC_AHB_PRESCALAR_DIV_2 	
	RCC_AHB_PRESCALAR_DIV_2 	
	RCC_AHB_PRESCALAR_DIV_2 						*/
#define RCC_AHB_PRESCALAR_DIV 	RCC_AHB_PRESCALAR_DIV_NO 	

/* Available options for APB1 Clock prescalar are:-
	RCC_APB1_PRESCALAR_DIV_NO
	RCC_APB1_PRESCALAR_DIV_2	
	RCC_APB1_PRESCALAR_DIV_4	
	RCC_APB1_PRESCALAR_DIV_8	
	RCC_APB1_PRESCALAR_DIV_16 						*/
#define RCC_APB1_PRESCALAR_DIV 	RCC_APB1_PRESCALAR_DIV_4

/* Available options for APB2 Clock prescalar are:-
	RCC_APB2_PRESCALAR_DIV_NO
	RCC_APB2_PRESCALAR_DIV_2	
	RCC_APB2_PRESCALAR_DIV_4	
	RCC_APB2_PRESCALAR_DIV_8	
	RCC_APB2_PRESCALAR_DIV_16 						*/
#define RCC_APB2_PRESCALAR_DIV 	RCC_APB2_PRESCALAR_DIV_NO 

/****************************/

#endif
