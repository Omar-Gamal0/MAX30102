/************************************************/
/*  Auther: Omar Gamal							*/
/*  Version: V04								*/
/* 	Date: 24 August 2020						*/
/************************************************/

#ifndef _GPIO_INTERFACE_H
#define _GPIO_INTERFACE_H

/* Defining Pin struct */
typedef struct{
	u8 Port;
	u8 Pin;
}MGPIO_Pin_def_t;
/***********************/

/* General Purpose Macros*/

/* Voltage State */

#define GPIO_U8_HIGH							1		/* Macro holding the corresponding value of high voltage */
#define GPIO_U8_LOW								0		/* Macro holding the corresponding value of low voltage */

/*****************/

/* Pins Modes Macros */

/* Input/Output Selecting Macros */

#define GPIO_U8_PIN_MODE_INPUT					0b00		/* Macro holding the corresponding value of Input mode */
#define GPIO_U8_PIN_MODE_OUTPUT_MAX10MHZ		0b01		/* Macro holding the corresponding value of Output mode with maximum frequency of 10 MHZ */
#define GPIO_U8_PIN_MODE_OUTPUT_MAX2MHZ			0b10		/* Macro holding the corresponding value of Output mode with maximum frequency of 2 MHZ */
#define GPIO_U8_PIN_MODE_OUTPUT_MAX50MHZ		0b11		/* Macro holding the corresponding value of Output mode with maximum frequency of 50 MHZ */

/***********************/

/* Input Settings Macros */

#define GPIO_U8_INPUT_MODE_ANALOG				0b00		/* Macro holding the corresponding value of Input mode configuration for Analog input */
#define GPIO_U8_INPUT_MODE_FLOATING				0b01		/* Macro holding the corresponding value of Input mode configuration for Floating */
#define GPIO_U8_INPUT_MODE_PULLING_ENABLED		0b10		/* Macro holding the corresponding value of Input mode configuration for Pulling up/down */

#define GPIO_U8_PULL_DOWN						0		/* Macro holding the corresponding value of Input mode Pulling up/down configuration for Pulling down */
#define GPIO_U8_PULL_UP							1		/* Macro holding the corresponding value of Input mode Pulling up/down configuration for Pulling up */

/***********************/

/* Output Settings Macros */

#define GPIO_U8_OUTPUT_MODE_GP_PP				0b00		/* Macro holding the corresponding value of Output mode configuration for General purpose Push-pull */
#define GPIO_U8_OUTPUT_MODE_GP_OD				0b01		/* Macro holding the corresponding value of Output mode configuration for General purpose Open drain */
#define GPIO_U8_OUTPUT_MODE_AF_PP				0b10		/* Macro holding the corresponding value of Output mode configuration for Alternate Function Push-pull */
#define GPIO_U8_OUTPUT_MODE_AF_OD				0b11		/* Macro holding the corresponding value of Output mode configuration for Alternate Function Open drain */

/***********************/

/******************/

/* Pins Numbers */

#define GPIO_U8_PIN0 		0							/* Macro holding the corresponding value of Pin 0 */
#define GPIO_U8_PIN1 		1							/* Macro holding the corresponding value of Pin 1 */
#define GPIO_U8_PIN2 		2							/* Macro holding the corresponding value of Pin 2 */
#define GPIO_U8_PIN3 		3							/* Macro holding the corresponding value of Pin 3 */
#define GPIO_U8_PIN4 		4							/* Macro holding the corresponding value of Pin 4 */
#define GPIO_U8_PIN5 		5							/* Macro holding the corresponding value of Pin 5 */
#define GPIO_U8_PIN6 		6							/* Macro holding the corresponding value of Pin 6 */
#define GPIO_U8_PIN7 		7							/* Macro holding the corresponding value of Pin 7 */
#define GPIO_U8_PIN8 		8							/* Macro holding the corresponding value of Pin 8 */
#define GPIO_U8_PIN9 		9							/* Macro holding the corresponding value of Pin 9 */
#define GPIO_U8_PIN10 		10							/* Macro holding the corresponding value of Pin 10 */
#define GPIO_U8_PIN11 		11							/* Macro holding the corresponding value of Pin 11 */
#define GPIO_U8_PIN12 		12							/* Macro holding the corresponding value of Pin 12 */
#define GPIO_U8_PIN13 		13							/* Macro holding the corresponding value of Pin 13 */
#define GPIO_U8_PIN14 		14							/* Macro holding the corresponding value of Pin 14 */
#define GPIO_U8_PIN15 		15							/* Macro holding the corresponding value of Pin 15 */

/****************/

/* Ports */

#define GPIO_U8_PORTA		0							/* Macro holding the corresponding value of Port A */
#define GPIO_U8_PORTB		1							/* Macro holding the corresponding value of Port B */
#define GPIO_U8_PORTC		2							/* Macro holding the corresponding value of Port C */

/*********/

/*************************/


/* Global functions */

/* GPIO_voidPORTA_Init --> Enables clock for PortA, sets all pins' outputs of PortA to low  */
/* I/P:- void 				 																*/
/* O/P:- void											 							 		*/
/********************************************************************************************/
void GPIO_voidPORTA_Init(void);

/* GPIO_voidPORTB_Init --> Enables clock for PortB, sets all pins' outputs of PortB to low  */
/* I/P:- void 				 																*/
/* O/P:- void											 							 		*/
/********************************************************************************************/
void GPIO_voidPORTB_Init(void);

/* GPIO_voidPORTC_Init --> Enables clock for PortC, sets all pins' outputs of PortC to low  */
/* I/P:- void 				 																*/
/* O/P:- void											 							 		*/
/********************************************************************************************/
void GPIO_voidPORTC_Init(void);

/* GPIO_voisAllPortsInit --> Enables clock for All Ports, sets all pins' outputs to low & Initializes the system clock 	*/
/* I/P:- void											 					 											*/
/* O/P:- void							 	 																			*/
/************************************************************************************************************************/
void GPIO_voidAllPortsInit(void);

/* GPIO_voidSetPinVal --> Sets output value of wanted pin 				*/
/* I/P:- Cpy_u8Port:- Port / Available options:- GPIO_U8_PORTA
												 GPIO_U8_PORTB
												 GPIO_U8_PORTC
  		 Cpy_u8PinNum:- Pin Number / Available options:- GPIO_U8_PIN0
														 GPIO_U8_PIN1
														 GPIO_U8_PIN2
														 GPIO_U8_PIN3
														 GPIO_U8_PIN4
														 GPIO_U8_PIN5
														 GPIO_U8_PIN6
														 GPIO_U8_PIN7
														 GPIO_U8_PIN8
														 GPIO_U8_PIN9
														 GPIO_U8_PIN10
														 GPIO_U8_PIN11
														 GPIO_U8_PIN12
														 GPIO_U8_PIN13
														 GPIO_U8_PIN14
														 GPIO_U8_PIN15
  		 Cpy_u8PinVal:- Pin Value / Available options:- GPIO_U8_HIGH
														GPIO_U8_LOW		*/
/* O/P:- void						 		   							*/
void GPIO_voidSetPinVal(u8 Cpy_u8Port,u8 Cpy_u8PinNum, u8 Cpy_u8PinVal);
/************************************************************************/

/* GPIO_voidTogPinVal --> Toggles output value of wanted pin 			*/
/* I/P:- Cpy_u8Port:- Port / Available options:- GPIO_U8_PORTA
												 GPIO_U8_PORTB
												 GPIO_U8_PORTC
  		 Cpy_u8PinNum:- Pin Number / Available options:- GPIO_U8_PIN0
														 GPIO_U8_PIN1
														 GPIO_U8_PIN2
														 GPIO_U8_PIN3
														 GPIO_U8_PIN4
														 GPIO_U8_PIN5
														 GPIO_U8_PIN6
														 GPIO_U8_PIN7
														 GPIO_U8_PIN8
														 GPIO_U8_PIN9
														 GPIO_U8_PIN10
														 GPIO_U8_PIN11
														 GPIO_U8_PIN12
														 GPIO_U8_PIN13
														 GPIO_U8_PIN14
														 GPIO_U8_PIN15	*/
/* O/P:- void						 		   							*/
void GPIO_voidTogPinVal(u8 Cpy_u8Port,u8 Cpy_u8PinNum);
/************************************************************************/

/* GPIO_u8GetPinVal --> Returns input value of wanted pin 			  */
/* I/P:- Cpy_u8Port:- Port / Available options:- GPIO_U8_PORTA
												 GPIO_U8_PORTB
												 GPIO_U8_PORTC
  		 Cpy_u8PinNum:- Pin Number / Available options:- GPIO_U8_PIN0
														 GPIO_U8_PIN1
														 GPIO_U8_PIN2
														 GPIO_U8_PIN3
														 GPIO_U8_PIN4
														 GPIO_U8_PIN5
														 GPIO_U8_PIN6
														 GPIO_U8_PIN7
														 GPIO_U8_PIN8
														 GPIO_U8_PIN9
														 GPIO_U8_PIN10
														 GPIO_U8_PIN11
														 GPIO_U8_PIN12
														 GPIO_U8_PIN13
														 GPIO_U8_PIN14
														 GPIO_U8_PIN15
  		 Cpy_u8PinVal:- Pin Value / Available options:- GPIO_U8_HIGH
														GPIO_U8_LOW		*/
/* O/P:- Temp_u8PinVal:- Input value of the corresponding pin (0 or 1)	*/
u8 GPIO_u8GetPinVal(u8 Cpy_u8Port,u8 Cpy_u8PinNum);
/************************************************************************/

/* GPIO_voidSetPinMode --> Sets wanted pin Mode 																			*/
/* I/P:- Cpy_u8Port:- Port / Available options:- GPIO_U8_PORTA
												 GPIO_U8_PORTB
												 GPIO_U8_PORTC
  		 Cpy_u8PinNum:- Pin Number / Available options:- GPIO_U8_PIN0
														 GPIO_U8_PIN1
														 GPIO_U8_PIN2
														 GPIO_U8_PIN3
														 GPIO_U8_PIN4
														 GPIO_U8_PIN5
														 GPIO_U8_PIN6
														 GPIO_U8_PIN7
														 GPIO_U8_PIN8
														 GPIO_U8_PIN9
														 GPIO_U8_PIN10
														 GPIO_U8_PIN11
														 GPIO_U8_PIN12
														 GPIO_U8_PIN13
														 GPIO_U8_PIN14
														 GPIO_U8_PIN15
  		 Cpy_u8PinVal:- Pin Cpy_u8PinConfig / Available options in the input state:- GPIO_U8_INPUT_MODE_ANALOG
																					 GPIO_U8_INPUT_MODE_FLOATING
																					 GPIO_U8_INPUT_MODE_PULLING_ENABLED
																					 
											  Available options in the output state:- GPIO_U8_OUTPUT_MODE_GP_PP				// General purpose output push-pull
																					  GPIO_U8_OUTPUT_MODE_GP_OD				// General purpose output Open-drain
																					  GPIO_U8_OUTPUT_MODE_AF_PP				// Alternate function output Push-pull
																					  GPIO_U8_OUTPUT_MODE_AF_OD			*/	// Alternate function output Open-drain
/* O/P:- void						 		  																			*/
void GPIO_voidSetPinMode(u8 Cpy_u8Port, u8 Cpy_u8PinNum, u8 Cpy_u8PinConfig, u8 Cpy_u8PinOutputMode);
/************************************************************************************************************************/

/* GPIO_voidSetPinPullingState --> Sets wanted pin Pulling state (Up or Down) 		*/
/* I/P:- Cpy_u8Port:- Port / Available options:- GPIO_U8_PORTA
												 GPIO_U8_PORTB
												 GPIO_U8_PORTC
  		 Cpy_u8PinNum:- Pin Number / Available options:- GPIO_U8_PIN0
														 GPIO_U8_PIN1
														 GPIO_U8_PIN2
														 GPIO_U8_PIN3
														 GPIO_U8_PIN4
														 GPIO_U8_PIN5
														 GPIO_U8_PIN6
														 GPIO_U8_PIN7
														 GPIO_U8_PIN8
														 GPIO_U8_PIN9
														 GPIO_U8_PIN10
														 GPIO_U8_PIN11
														 GPIO_U8_PIN12
														 GPIO_U8_PIN13
														 GPIO_U8_PIN14
														 GPIO_U8_PIN15
		Cpy_u8PullingState:- GPIO_U8_PULL_UP
							 GPIO_U8_PULL_DOWN
														 	 	 	 	 	 	 	*/
/* O/P: void 																		*/
void GPIO_voidSetPinPullingState(u8 Cpy_u8Port, u8 Cpy_u8PinNum, u8 Cpy_u8PullingState);
/************************************************************************************/

/* GPIO_PinLock --> Locks a specific pin Mode 								*/
/* I/P:- Cpy_u8Port:- Port / Available options:- GPIO_U8_PORTA
												 GPIO_U8_PORTB
												 GPIO_U8_PORTC
  		 Cpy_u8PinNum:- Pin Number / Available options:- GPIOU8__PIN0
														 GPIOU8__PIN1
														 GPIOU8__PIN2
														 GPIOU8__PIN3
														 GPIOU8__PIN4
														 GPIOU8__PIN5
														 GPIOU8__PIN6
														 GPIOU8__PIN7
														 GPIOU8__PIN8
														 GPIOU8__PIN9
														 GPIOU8__PIN10
														 GPIOU8__PIN11
														 GPIOU8__PIN12
														 GPIOU8__PIN13
														 GPIOU8__PIN14
														 GPIOU8__PIN15		*/
/* O/P:- void																*/
void GPIO_voidPinLock(u8 Cpy_u8Port, u8 Cpy_u8PinNum);
/****************************************************************************/

/* GPIO_PortLock --> Locks all pins Modes of a specific port	 			*/
/* I/P:- Cpy_u8Port:- Port / Available options:- GPIO_U8_PORTA
												 GPIO_U8_PORTB
												 GPIO_U8_PORTC				*/
/* O/P:- void																*/
void GPIO_voidPortLock(u8 Cpy_u8Port);
/****************************************************************************/

/********************/

#endif
