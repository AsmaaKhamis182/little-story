/*
 * DIO_program.c
 *

 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"
#include "DIO_private.h"
#include "DIO_config.h"

void DIO_voidSetPinDirection(Dio_PortType Copy_u8PortId, Dio_PinType Copy_u8PinId, Dio_DirectionType Copy_u8Direction)
{
    switch (Copy_u8PortId)
    {
    case DIO_PORTA:
        if (DIO_MODE_OUTPUT == Copy_u8Direction)
        {
            SET_BIT(DDRA_R, Copy_u8PinId); // DDRA = 1 ---> output
        }
        else if (DIO_MODE_INPUT_FLOATING == Copy_u8Direction)
        {
            CLR_BIT(DDRA_R, Copy_u8PinId);  // DDRA  = 0 ----->input
            CLR_BIT(PORTA_R, Copy_u8PinId); // PORTA = 0
        }
        else if (DIO_MODE_INPUT_PULLUP == Copy_u8Direction)
        {
            CLR_BIT(DDRA_R, Copy_u8PinId);  // DDRA  = 0 ----->input
            SET_BIT(PORTA_R, Copy_u8PinId); // PORTA = 0
        }
        else
        {
            /* Do Nothing */
        }
        break;
    case DIO_PORTB:
        if (DIO_MODE_OUTPUT == Copy_u8Direction)
        {
            SET_BIT(DDRB_R, Copy_u8PinId);
        }
        else if (DIO_MODE_INPUT_FLOATING == Copy_u8Direction)
        {
            CLR_BIT(DDRB_R, Copy_u8PinId);
            CLR_BIT(PORTB_R, Copy_u8PinId);
        }
        else if (DIO_MODE_INPUT_PULLUP == Copy_u8Direction)
        {
            CLR_BIT(DDRB_R, Copy_u8PinId);
            SET_BIT(PORTB_R, Copy_u8PinId);
        }
        else
        {
            /* Do Nothing */
        }
        break;
    case DIO_PORTC:
        if (DIO_MODE_OUTPUT == Copy_u8Direction)
        {
            SET_BIT(DDRC_R, Copy_u8PinId);
        }
        else if (DIO_MODE_INPUT_FLOATING == Copy_u8Direction)
        {
            CLR_BIT(DDRC_R, Copy_u8PinId);
            CLR_BIT(PORTC_R, Copy_u8PinId);
        }
        else if (DIO_MODE_INPUT_PULLUP == Copy_u8Direction)
        {
            CLR_BIT(DDRC_R, Copy_u8PinId);
            SET_BIT(PORTC_R, Copy_u8PinId);
        }
        else
        {
            /* Do Nothing */
        }
        break;
    case DIO_PORTD:
        if (DIO_MODE_OUTPUT == Copy_u8Direction)
        {
            SET_BIT(DDRD_R, Copy_u8PinId);
        }
        else if (DIO_MODE_INPUT_FLOATING == Copy_u8Direction)
        {
            CLR_BIT(DDRD_R, Copy_u8PinId);
            CLR_BIT(PORTD_R, Copy_u8PinId);
        }
        else if (DIO_MODE_INPUT_PULLUP == Copy_u8Direction)
        {
            CLR_BIT(DDRD_R, Copy_u8PinId);
            SET_BIT(PORTD_R, Copy_u8PinId);
        }
        else
        {
            /* Do Nothing */
        }
        break;
    default:       break;
    }
}

void DIO_voidSetPinValue(Dio_PortType Copy_u8PortId, Dio_PinType Copy_u8PinId, Dio_ValueType Copy_u8Value)
{
    switch (Copy_u8PortId)
    {
    case DIO_PORTA:
        if (DIO_LEVEL_HIGH == Copy_u8Value)
        {
            SET_BIT(PORTA_R, Copy_u8PinId);
        }
        else if (DIO_LEVEL_LOW == Copy_u8Value)
        {
            CLR_BIT(PORTA_R, Copy_u8PinId);
        }
        else
        {
            /* Do Nothing */
        }
        break;
    case DIO_PORTB:
        if (DIO_LEVEL_HIGH == Copy_u8Value)
        {
            SET_BIT(PORTB_R, Copy_u8PinId);
        }
        else if (DIO_LEVEL_LOW == Copy_u8Value)
        {
            CLR_BIT(PORTB_R, Copy_u8PinId);
        }
        else
        {
            /* Do Nothing */
        }
        break;
    case DIO_PORTC:
        if (DIO_LEVEL_HIGH == Copy_u8Value)
        {
            SET_BIT(PORTC_R, Copy_u8PinId);
        }
        else if (DIO_LEVEL_LOW == Copy_u8Value)
        {
            CLR_BIT(PORTC_R, Copy_u8PinId);
        }
        else
        {
            /* Do Nothing */
        }
        break;
    case DIO_PORTD:
        if (DIO_LEVEL_HIGH == Copy_u8Value)
        {
            SET_BIT(PORTD_R, Copy_u8PinId);
        }
        else if (DIO_LEVEL_LOW == Copy_u8Value)
        {
            CLR_BIT(PORTD_R, Copy_u8PinId);
        }
        else
        {
            /* Do Nothing */
        }
        break;
    
    default:      break;
    }
}

Dio_ValueType DIO_voidGetPinValue(Dio_PortType Copy_u8PortId, Dio_PinType Copy_u8PinId)
{
    Dio_ValueType ret_value = DIO_LEVEL_LOW;
    switch (Copy_u8PortId)
    {
    case DIO_PORTA:
        ret_value = GET_BIT(PINA_R, Copy_u8PinId);
        break;
    case DIO_PORTB:
        ret_value = GET_BIT(PINB_R, Copy_u8PinId);
        break;
    case DIO_PORTC:
        ret_value = GET_BIT(PINC_R, Copy_u8PinId);
        break;
    case DIO_PORTD:
        ret_value = GET_BIT(PIND_R, Copy_u8PinId);
        break;
    default:
        break;
    }
    return ret_value;
}

void DIO_voidSetPortDirection(Dio_PortType Copy_u8PortId, Dio_DirectionType Copy_u8Direction)
{
    if( (Copy_u8PortId <= DIO_PORTD) )
	{
	    switch(Copy_u8PortId)
	    {
	    case DIO_PORTA:  
            switch(Copy_u8Direction)
	        {
	        case  DIO_MODE_INPUT_FLOATING:   
            DDRA_R = 0x00;     
            break;
            case  DIO_MODE_INPUT_PULLUP:   
            DDRA_R = 0x0f;     
            break;
	        case  DIO_MODE_OUTPUT:  
            DDRA_R = 0xff;     
            break;
	        }
	        break;
	    case DIO_PORTB:  
            switch(Copy_u8Direction)
	        {
	        case  DIO_MODE_INPUT_FLOATING:
            DDRB_R = 0x00;
            break;
            case  DIO_MODE_INPUT_PULLUP:   
            DDRB_R = 0x0f;     
            break;
	        case  DIO_MODE_OUTPUT:
            DDRB_R = 0xff;
            break;
	        }
	        break;
	    case DIO_PORTC:  
            switch(Copy_u8Direction)
	        {
	        case  DIO_MODE_INPUT_FLOATING:
            DDRC_R = 0x00;
            break;
            case  DIO_MODE_INPUT_PULLUP:   
            DDRC_R = 0x0f;     
            break;
	        case  DIO_MODE_OUTPUT:
            DDRC_R = 0xff;
            break;
	        }
	        break;
	    case DIO_PORTD:  
            switch(Copy_u8Direction)
	        {
	        case  DIO_MODE_INPUT_FLOATING:
            DDRD_R = 0x00; 
            break;
            case  DIO_MODE_INPUT_PULLUP:   
            DDRD_R = 0x0f;     
            break;
	        case  DIO_MODE_OUTPUT:
            DDRD_R = 0xff; 
            break;
	        }
	        break;

	    }
	}
	else
	{

	}
}

void DIO_voidSetPortValue(Dio_PortType Copy_u8PortId, Dio_ValueType Copy_u8Value)
{
    if( (Copy_u8PortId <= DIO_PORTD) )
	{
	switch(Copy_u8PortId)
	{
	case DIO_PORTA:
    switch(Copy_u8Value)
	{
	case  DIO_LEVEL_LOW:   
    PORTA_R = 0x00;     
    break;
	case  DIO_LEVEL_HIGH:  
    PORTA_R = 0xff;     
    break;
	}
	break;
	case DIO_PORTB:  
    switch(Copy_u8Value)
	{
	case  DIO_LEVEL_LOW:   
    PORTB_R = 0x00;     
    break;
	case  DIO_LEVEL_HIGH:  
    PORTB_R = 0xff;     
    break;
	}
    break;
	case DIO_PORTC:  
    switch(Copy_u8Value)
	{
	case  DIO_LEVEL_LOW:
    PORTC_R = 0x00;     
    break;
	case  DIO_LEVEL_HIGH:  
    PORTC_R = 0xff;     
    break;
	}
	break;
	case DIO_PORTD:  
    switch(Copy_u8Value)
	{
	case  DIO_LEVEL_LOW:
    PORTD_R = 0x00;
    break;
	case  DIO_LEVEL_HIGH:
    PORTD_R = 0xff;
    break;
	}
	break;

	}
	}
	else
	{

	}

}

Dio_ValueType DIO_voidGetPortValue(Dio_PortType Copy_u8PortId)
{
    Dio_ValueType ret_value = DIO_LEVEL_LOW;
    switch (Copy_u8PortId)
    {
    case DIO_PORTA:
        ret_value = GET_BIT(PORTD_R, Copy_u8PortId);
        break;
    case DIO_PORTB:
        ret_value = GET_BIT(PORTD_R, Copy_u8PortId);
        break;
    case DIO_PORTC:
        ret_value = GET_BIT(PORTD_R, Copy_u8PortId);
        break;
    case DIO_PORTD:
        ret_value = GET_BIT(PORTD_R, Copy_u8PortId);
        break;
    default:
        break;
    }
    return ret_value;
}
