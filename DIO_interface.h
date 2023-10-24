/*
 * DIO_interface.h
 *

 */

#ifndef INC_DIO_INTERFACE_H_
#define INC_DIO_INTERFACE_H_

#include "STD_TYPES.h"


/******************* Types Definition *******************/

typedef enum {
    DIO_PORTA,
    DIO_PORTB,
    DIO_PORTC,
    DIO_PORTD
} Dio_PortType;

typedef enum {
    DIO_PIN0,
    DIO_PIN1,
    DIO_PIN2,
    DIO_PIN3,
    DIO_PIN4,
    DIO_PIN5,
    DIO_PIN6,
    DIO_PIN7
} Dio_PinType;

typedef enum {
    DIO_MODE_INPUT_FLOATING,
    DIO_MODE_INPUT_PULLUP,
    DIO_MODE_OUTPUT
} Dio_DirectionType;

typedef enum {
    DIO_LEVEL_LOW,
    DIO_LEVEL_HIGH
} Dio_ValueType;


/************* Functions prototype for DIO *************/

void DIO_voidSetPinDirection (Dio_PortType Copy_u8PortId, Dio_PinType Copy_u8PinId, Dio_DirectionType Copy_u8Direction);
void DIO_voidSetPinValue(Dio_PortType Copy_u8PortId, Dio_PinType Copy_u8PinId, Dio_ValueType Copy_u8Value);
u8 DIO_voidGetPinValue(Dio_PortType Copy_u8PortId, Dio_PinType Copy_u8PinId);
void DIO_voidSetPortDirection(Dio_PortType Copy_u8PortId, Dio_DirectionType Copy_u8Direction);
void DIO_voidSetPortValue(Dio_PortType Copy_u8PortId, Dio_ValueType Copy_u8Value);
u8 DIO_voidGetPortValue(Dio_PortType Copy_u8PortId);

#endif /* INC_DIO_INTERFACE_H_ */
