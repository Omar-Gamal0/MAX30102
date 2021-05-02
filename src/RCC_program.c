/************************************************/
/*  Auther: Omar Gamal							*/
/*  Version: V02								*/
/* 	Date: 11 August 2020						*/
/************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_interface.h"
#include "RCC_private.h"
#include "RCC_config.h"



void RCC_voidEnableClock(u8 Copy_u8BusId,u8 Copy_u8PerId){
	if (Copy_u8PerId <=31)														// Checks if Peripheral is in the valid range		
	{
		switch (Copy_u8BusId)
		{
			case RCC_AHB  : SET_BIT(RCC_AHBENR ,Copy_u8PerId); 	break;			// Enables the clock of the required peripheral on AHB
			case RCC_APB1 : SET_BIT(RCC_APB1ENR ,Copy_u8PerId); break;			// Enables the clock of the required peripheral on APB1
			case RCC_APB2 : SET_BIT(RCC_APB2ENR ,Copy_u8PerId); break;			// Enables the clock of the required peripheral on APB2
		}
	}
	
	else																		
	{
			/* Return Error */
	}

}

void RCC_voidDisableClock(u8 Copy_u8BusId,u8 Copy_u8PerId){
	if (Copy_u8PerId <=31)
	{
		switch (Copy_u8BusId)
		{
			case RCC_AHB  : CLR_BIT(RCC_AHBENR ,Copy_u8PerId); 	break;
			case RCC_APB1 : CLR_BIT(RCC_APB1ENR ,Copy_u8PerId); break;
			case RCC_APB2 : CLR_BIT(RCC_APB2ENR ,Copy_u8PerId); break;
		}
	}
	
	else
	{
			/* Return Error */
	}

}

void RCC_voidInitSysClock(void){
	switch(SW_VAL)
	{
		case SW_HSI :
		
			SET_BIT(RCC_CR,0);													// Sets Bit 0 of RCC_CR (Clock control register) to enable HSI(Internal high-speed clock).
			RCC_CFGR = 0x00000000;												// Resets RCC_CFGR (Clock configuration register).
			RCC_CFGR |= SW_VAL;													// Sets value of Bits 0 : 1 of RCC_CFGR to select the system clock.
			switch(HSITRIM_SIGN)
			{
				case HSITRIM_NOTRIM:						
					HSITRIM_RESET();											// Resets the value of Bits 3 : 7 of RCC_CR to 10000 reset HSI trimming to no trimming state.
				break;
				
				case HSITRIM_POSITIVE:
					HSITRIM_CLR();												// Clears the value of Bits 3 : 7 of RCC_CR to 00000.
					if (HSITRIM_STEPS > 0 && HSITRIM_STEPS < 16){				// Checks if number of steps of trimming is in the valid range.
						RCC_CR |= ((10000 + HSITRIM_STEPS) << 3);				// Sets the value of Bits 3 : 7 of RCC_CR to gain the wanted Trimming.
					}
					else{
						// Return Error 
					}
				break;
				
				case HSITRIM_NEGATIVE:
					HSITRIM_CLR();												// Clears the value of Bits 3 : 7 of RCC_CR to 00000.
					if (HSITRIM_STEPS > 0 && HSITRIM_STEPS <= 16){				// Checks if number of steps of trimming is in the valid range.
						RCC_CR |= ((10000 - HSITRIM_STEPS) << 3);				// Sets the value of Bits 3 : 7 of RCC_CR to gain the wanted Trimming.
					}
					else{
						// Return Error 
					}
				break;
			}
			break;			
		
		case SW_HSE :
			
			SET_BIT(RCC_CR,16);													// Sets Bit 16 of RCC_CR to enable HSE(External high-speed clock).
			RCC_CFGR = 0x00000000;												// Resets RCC_CFGR.
			RCC_CFGR |= SW_VAL;													// Sets value of Bits 0 : 1 of RCC_CFGR to select the system clock.
			
			switch(CSSON_VAL)
			{
				case CSSON  : SET_BIT(RCC_CR,19); break;  							// Sets value of bit 19 of RCC_CR to enable Clock security system
				case CSSOFF : CLR_BIT(RCC_CR,19); break;								// Clears value of bit 19 of RCC_CR to disable Clock security system
			}
			
			switch(HSEBYP_VAL)
			{
				case HSEBYP_ON  : SET_BIT(RCC_CR,18); break;  						// Sets value of bit 18 of RCC_CR to enable HSE bypass
				case HSEBYP_OFF : CLR_BIT(RCC_CR,18); break;							// Clears value of bit 18 of RCC_CR to disable HSE bypass
			}
			
			break;
		
		case SW_PLL :
			
			RCC_CFGR |= ( ( (u32)(PLLMUL_VAL) ) << 18 );						// Sets value of Bits 18 : 21 of RCC_CFGR to set PLL multiplication factor
			SET_BIT(RCC_CR,24);													// Sets Bit 24 of RCC_CR to enable PLL(Phase-locked loop).
			RCC_CFGR = 0x00000000;												// Resets RCC_CFGR.
			RCC_CFGR |= SW_VAL;													// Sets value of Bits 0 : 1 of RCC_CFGR to select the system clock.
			
			switch (PLLSRC_VAL)
			{
				case PLLSRC_HSE:
					SET_BIT(RCC_CFGR, 16);										// Sets value of Bit 16 of RCC_CFGR to select HSE as PLL input.
				break;
				
				case PLLSRC_HSI:
					CLR_BIT(RCC_CFGR, 16);										// Resets value of Bit 16 of RCC_CFGR to select HSI as PLL input.
				break;
			}
			
			switch(PLLXTPRE_VAL)
			{
				case PLLXTPRE_ON:
					SET_BIT(RCC_CFGR, 17);										// Sets value of Bit 17 of RCC_CFGR to enable HSE divider for PLL entry.
				break;
				
				case PLLXTPRE_OFF:
					CLR_BIT(RCC_CFGR, 17);										// Clears value of Bit 17 of RCC_CFGR to dissable HSE divider for PLL entry. 
				break;
			}
			
			break;
		
	}
	
	/* CLOCKS PRESCALARs */
	
	RCC_CFGR |= ((RCC_AHB_PRESCALAR_DIV << 4) | (RCC_APB1_PRESCALAR_DIV << 8) | (RCC_APB2_PRESCALAR_DIV << 11));
	
	/*********************/
		
}

void HSITRIM_RESET(void){														// Resets value of Bits 3 : 7 of RCC_CR to 10000
	SET_BIT(RCC_CR,7);								
	CLR_BIT(RCC_CR,6);
	CLR_BIT(RCC_CR,5);
	CLR_BIT(RCC_CR,4);
	CLR_BIT(RCC_CR,3);
}
void HSITRIM_CLR(void){															// Clears value of Bits 3 : 7 of RCC_CR to 00000
	CLR_BIT(RCC_CR,7);
	CLR_BIT(RCC_CR,6);
	CLR_BIT(RCC_CR,5);
	CLR_BIT(RCC_CR,4);
	CLR_BIT(RCC_CR,3);
}