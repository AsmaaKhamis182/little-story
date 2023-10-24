/*
 * DIO_private.h
 *

 */

#ifndef INC_DIO_PRIVATE_H_
#define INC_DIO_PRIVATE_H_

#include "STD_TYPES.h"

/************** PORTA Registers **************/
#define DDRA_R		*((volatile u8*) 0x3A)
#define PORTA_R   	*((volatile u8*) 0x3B)
#define PINA_R		*((const volatile u8*) 0x39)

/************* PORTB Registers *************/
#define DDRB_R		*((volatile u8*) 0x37)
#define PORTB_R		*((volatile u8*) 0x38)
#define PINB_R		*((const volatile u8*) 0x36)

/************* PORTC Registers *************/
#define DDRC_R		*((volatile u8*) 0x34)
#define PORTC_R		*((volatile u8*) 0x35)
#define PINC_R		*((const volatile u8*) 0x33)

/************* PORTD Registers *************/
#define DDRD_R		*((volatile u8*) 0x31)
#define PORTD_R		*((volatile u8*) 0x32)
#define PIND_R		*((const volatile u8*) 0x30)

#endif /* INC_DIO_PRIVATE_H_ */
