/***********************************************/
/* Author	: Omar Gamal					   */
/* Date		: 12 AUG 2020					   */
/* Version 	: V02							   */
/***********************************************/
#ifndef BIT_MATH_H
#define BIT_MATH_H

#define SET_BIT(VAR,BIT)		VAR |= ( 1<<(BIT) )
#define CLR_BIT(VAR,BIT)		VAR &= ~( 1<<(BIT) )
#define GET_BIT(VAR,BIT)		(( VAR>>(BIT) ) & 1)
#define TOG_BIT(VAR,BIT)        VAR ^= ( 1<<(BIT) )


#define BIT_CONC_PIN(A1,A0)	  CONC_HELP_PIN(A1,A0)
#define CONC_HELP_PIN(A1,A0)  A1##A0

#define BIT_CONC_PIN_BINARY(A1,A0)	  CONC_HELP_PIN_BINARY(A1,A0)
#define CONC_HELP_PIN_BINARY(A1,A0)   0b##A1##A0

#define BIT_CONC_REG(A7,A6,A5,A4,A3,A2,A1,A0)   CONC_HELP_REG(A7,A6,A5,A4,A3,A2,A1,A0)
#define CONC_HELP_REG(A7,A6,A5,A4,A3,A2,A1,A0)  0b##A7##A6##A5##A4##A3##A2##A1##A0

#endif
