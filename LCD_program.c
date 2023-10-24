/*
 * LCD_program.c
 *

 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include <stdarg.h>
#include <util/delay.h>

#include "DIO_interface.h"
#include "DIO_private.h"
#include "DIO_config.h"

#include "LCD_interface.h"
#include "LCD_private.h"
#include "LCD_config.h"

void Lcd_Void_LCDInit(void)
{
#if LCD_MODE   ==   _8_BIT_MODE
	DIO_voidSetPinDirection(LCD_D0_PIN,DIO_MODE_OUTPUT);
	DIO_voidSetPinDirection(LCD_D1_PIN,DIO_MODE_OUTPUT);
	DIO_voidSetPinDirection(LCD_D2_PIN,DIO_MODE_OUTPUT);
	DIO_voidSetPinDirection(LCD_D3_PIN,DIO_MODE_OUTPUT);
	DIO_voidSetPinDirection(LCD_D4_PIN,DIO_MODE_OUTPUT);
	DIO_voidSetPinDirection(LCD_D5_PIN,DIO_MODE_OUTPUT);
	DIO_voidSetPinDirection(LCD_D6_PIN,DIO_MODE_OUTPUT);
	DIO_voidSetPinDirection(LCD_D7_PIN,DIO_MODE_OUTPUT);

	DIO_voidSetPinDirection(LCD_RS_PIN,DIO_MODE_OUTPUT);
	DIO_voidSetPinDirection(LCD_RW_PIN,DIO_MODE_OUTPUT);
	DIO_voidSetPinDirection(LCD_EN_PIN,DIO_MODE_OUTPUT);
	DIO_voidSetPinValue(LCD_RW_PIN,DIO_LEVEL_LOW);

	Lcd_Void_LCDWriteCommand(LCD_8_BIT_MODE_COMMAND);
	Lcd_Void_LCDWriteCommand(LCD_DISPLAY_ON_COMMAND);
	Lcd_Void_LCDWriteCommand(LCD_RETURN_HOME_COMMAND);
#elif LCD_MODE   ==   _4_BIT_MODE
	DIO_voidSetPinDirection(DIO_PORTB,DIO_PIN0,DIO_MODE_OUTPUT);    // Data pins 4
	DIO_voidSetPinDirection(DIO_PORTB,DIO_PIN1,DIO_MODE_OUTPUT);    // Data pins 5
	DIO_voidSetPinDirection(DIO_PORTB,DIO_PIN2,DIO_MODE_OUTPUT);    // Data pins 6
	DIO_voidSetPinDirection(DIO_PORTB,DIO_PIN4,DIO_MODE_OUTPUT);    // Data pins 7
	DIO_voidSetPinDirection(DIO_PORTA,DIO_PIN3,DIO_MODE_OUTPUT);    // RS
	DIO_voidSetPinDirection(DIO_PORTA,DIO_PIN2,DIO_MODE_OUTPUT);    // EN

	Lcd_Void_LCDWriteCommand(LCD_4_BIT_MODE_COMMAND_1);
	Lcd_Void_LCDWriteCommand(LCD_4_BIT_MODE_COMMAND_2);
	Lcd_Void_LCDWriteCommand(LCD_4_BIT_MODE_COMMAND_3);
	Lcd_Void_LCDWriteCommand(LCD_DISPLAY_ON_COMMAND);
	Lcd_Void_LCDWriteCommand(LCD_RETURN_HOME_COMMAND);
	Lcd_Void_LCDWriteCommand(LCD_CLEAR);


#endif
}

void Lcd_Void_LCDWriteCharacter(u8 Copy_U8_Character)
{
    DIO_voidSetPinValue(LCD_RS_PIN,DIO_LEVEL_HIGH);
#if   LCD_MODE   ==   _8_BIT_MODE
	DIO_voidSetPinValue(LCD_D0_PIN,GET_BIT(Copy_U8_Character,0));
	DIO_voidSetPinValue(LCD_D1_PIN,GET_BIT(Copy_U8_Character,1));
	DIO_voidSetPinValue(LCD_D2_PIN,GET_BIT(Copy_U8_Character,2));
	DIO_voidSetPinValue(LCD_D3_PIN,GET_BIT(Copy_U8_Character,3));
	DIO_voidSetPinValue(LCD_D4_PIN,GET_BIT(Copy_U8_Character,4));
	DIO_voidSetPinValue(LCD_D5_PIN,GET_BIT(Copy_U8_Character,5));
	DIO_voidSetPinValue(LCD_D6_PIN,GET_BIT(Copy_U8_Character,6));
	DIO_voidSetPinValue(LCD_D7_PIN,GET_BIT(Copy_U8_Character,7));

	DIO_voidSetPinValue(LCD_EN_PIN,DIO_LEVEL_HIGH);
	_delay_ms(1);
	DIO_voidSetPinValue(LCD_EN_PIN,DIO_LEVEL_LOW);
#elif LCD_MODE   ==   _4_BIT_MODE
	DIO_voidSetPinValue(DIO_PORTB,DIO_PIN0,GET_BIT(Copy_U8_Character,4));
	DIO_voidSetPinValue(DIO_PORTB,DIO_PIN1,GET_BIT(Copy_U8_Character,5));
	DIO_voidSetPinValue(DIO_PORTB,DIO_PIN2,GET_BIT(Copy_U8_Character,6));
	DIO_voidSetPinValue(DIO_PORTB,DIO_PIN4,GET_BIT(Copy_U8_Character,7));
	DIO_voidSetPinValue(DIO_PORTA,DIO_PIN2,DIO_LEVEL_HIGH);
	_delay_ms(2);
	DIO_voidSetPinValue(DIO_PORTA,DIO_PIN2,DIO_LEVEL_LOW);
	_delay_ms(5);
	DIO_voidSetPinValue(DIO_PORTB,DIO_PIN0,GET_BIT(Copy_U8_Character,0));
	DIO_voidSetPinValue(DIO_PORTB,DIO_PIN1,GET_BIT(Copy_U8_Character,1));
	DIO_voidSetPinValue(DIO_PORTB,DIO_PIN2,GET_BIT(Copy_U8_Character,2));
	DIO_voidSetPinValue(DIO_PORTB,DIO_PIN4,GET_BIT(Copy_U8_Character,3));
	DIO_voidSetPinValue(DIO_PORTA,DIO_PIN2,DIO_LEVEL_HIGH);
	_delay_ms(2);
	DIO_voidSetPinValue(DIO_PORTA,DIO_PIN2,DIO_LEVEL_LOW);
	_delay_ms(5);
#endif
}

void Lcd_Void_LCDWriteCommand(u8 Copy_U8_Command)
{
    DIO_voidSetPinValue(LCD_RS_PIN,DIO_LEVEL_LOW);
#if   LCD_MODE   ==   _8_BIT_MODE
	DIO_voidSetPinValue(LCD_D0_PIN,GET_BIT(Copy_U8_Command,0));
	DIO_voidSetPinValue(LCD_D1_PIN,GET_BIT(Copy_U8_Command,1));
	DIO_voidSetPinValue(LCD_D2_PIN,GET_BIT(Copy_U8_Command,2));
	DIO_voidSetPinValue(LCD_D3_PIN,GET_BIT(Copy_U8_Command,3));
	DIO_voidSetPinValue(LCD_D4_PIN,GET_BIT(Copy_U8_Command,4));
	DIO_voidSetPinValue(LCD_D5_PIN,GET_BIT(Copy_U8_Command,5));
	DIO_voidSetPinValue(LCD_D6_PIN,GET_BIT(Copy_U8_Command,6));
	DIO_voidSetPinValue(LCD_D7_PIN,GET_BIT(Copy_U8_Command,7));

	DIO_voidSetPinValue(LCD_EN_PIN,DIO_LEVEL_HIGH);
	_delay_ms(1);
	DIO_voidSetPinValue(LCD_EN_PIN,DIO_LEVEL_LOW);
#elif LCD_MODE   ==   _4_BIT_MODE
	DIO_voidSetPinValue(DIO_PORTB,DIO_PIN0,GET_BIT(Copy_U8_Command,4));
	DIO_voidSetPinValue(DIO_PORTB,DIO_PIN1,GET_BIT(Copy_U8_Command,5));
	DIO_voidSetPinValue(DIO_PORTB,DIO_PIN2,GET_BIT(Copy_U8_Command,6));
	DIO_voidSetPinValue(DIO_PORTB,DIO_PIN4,GET_BIT(Copy_U8_Command,7));
	DIO_voidSetPinValue(DIO_PORTA,DIO_PIN2,DIO_LEVEL_HIGH);
	_delay_ms(1);
	DIO_voidSetPinValue(DIO_PORTA,DIO_PIN2,DIO_LEVEL_LOW);
	_delay_ms(1);
	DIO_voidSetPinValue(DIO_PORTB,DIO_PIN0,GET_BIT(Copy_U8_Command,0));
	DIO_voidSetPinValue(DIO_PORTB,DIO_PIN1,GET_BIT(Copy_U8_Command,1));
	DIO_voidSetPinValue(DIO_PORTB,DIO_PIN2,GET_BIT(Copy_U8_Command,2));
	DIO_voidSetPinValue(DIO_PORTB,DIO_PIN4,GET_BIT(Copy_U8_Command,3));
	DIO_voidSetPinValue(DIO_PORTA,DIO_PIN2,DIO_LEVEL_HIGH);
	_delay_ms(1);
	DIO_voidSetPinValue(DIO_PORTA,DIO_PIN2,DIO_LEVEL_LOW);
	_delay_ms(5);
#endif
}

void Lcd_Void_LCDWriteString(u8* Copy_U8_Ptr)
{
    u8 Local_U8_Counter = 0;
	while(Copy_U8_Ptr[Local_U8_Counter] != NULL)
	{
		Lcd_Void_LCDWriteCharacter(Copy_U8_Ptr[Local_U8_Counter]);
		Local_U8_Counter++;
	}
}

void Lcd_Void_LCDClear(void)
{
    Lcd_Void_LCDWriteCommand(LCD_CLEAR);
}

void Lcd_Void_LCDWriteNumber(s32 Copy_S32_Number)
{
    s8 Local_S8_Counter = 0;
	u8 Local_U8_Arr[10] = {0};
	if(Copy_S32_Number < 0)
	{
		Copy_S32_Number = Copy_S32_Number * -1;
		Lcd_Void_LCDWriteCharacter('-');
		Lcd_Void_LCDWriteNumber(Copy_S32_Number);
	}
	else
	{
	 do
	 {
		Local_U8_Arr[Local_S8_Counter] = Copy_S32_Number % 10;
		Copy_S32_Number                = Copy_S32_Number / 10;
		Local_S8_Counter++;
	 }while(Copy_S32_Number != 0);

	 while(Local_S8_Counter > 0)
	 {
		Lcd_Void_LCDWriteCharacter(Local_U8_Arr[--Local_S8_Counter] + 48);
	 }
   }
}

void Lcd_Void_LCDGoTo(u8 Copy_U8_Row,u8 Copy_U8_Col)
{
    u8 Local_U8_Arr [4] = {LCD_R0_COMMAND , LCD_R1_COMMAND , LCD_R2_COMMAND , LCD_R3_COMMAND};
	Lcd_Void_LCDWriteCommand(Local_U8_Arr[Copy_U8_Row] + Copy_U8_Col);
}

void Lcd_Void_LCDWriteBinary(u8 Copy_u8_Number)
{
    s8 i;
	for (i=7;i>=0;i--)
	{
		Lcd_Void_LCDWriteCharacter(((Copy_u8_Number >> i) & 1) + '0');
	}
}

void Lcd_Void_LCDWriteHex(u8 Copy_u8_Number)
{
    u8 Copy_u8_HighestNumber = Copy_u8_Number >> 4;
	u8 Copy_u8_LowestNumber = Copy_u8_Number & 0x0f;
	if (Copy_u8_HighestNumber < 10)
	{
		Lcd_Void_LCDWriteCharacter(Copy_u8_HighestNumber + '0');
	}
	else
	{
		Lcd_Void_LCDWriteCharacter(Copy_u8_HighestNumber - 10 + 'A');
	}
	if (Copy_u8_LowestNumber < 10)
	{
		Lcd_Void_LCDWriteCharacter(Copy_u8_LowestNumber + '0');
	}
	else
	{
		Lcd_Void_LCDWriteCharacter(Copy_u8_LowestNumber - 10 + 'A');
	}
}

void Lcd_Void_LCDWriteNumber_4D(u16 Copy_u8_Number)
{
    Lcd_Void_LCDWriteCharacter(((Copy_u8_Number % 100000) / 10000) + '0');
	Lcd_Void_LCDWriteCharacter(((Copy_u8_Number % 10000) / 1000) + '0');
	Lcd_Void_LCDWriteCharacter(((Copy_u8_Number % 1000) / 100) + '0');
	Lcd_Void_LCDWriteCharacter(((Copy_u8_Number % 100) / 10) + '0');
	Lcd_Void_LCDWriteCharacter(((Copy_u8_Number % 10) / 1) + '0');
}

void Lcd_Void_LCDSetCursor(u8 Copy_u8_Line,u8 Copy_u8_Cell)
{
    if (Copy_u8_Line == 0)
	{
		Lcd_Void_LCDWriteCommand(0x80 + Copy_u8_Cell);
	}
	else if (Copy_u8_Line == 1)
	{
		Lcd_Void_LCDWriteCommand(0x80 + 0x40 + Copy_u8_Cell);
	}
	else if (Copy_u8_Line == 2)
	{
		Lcd_Void_LCDWriteCommand(0x80 + 0x14 + Copy_u8_Cell);
	}
	else if (Copy_u8_Line == 3)
	{
		Lcd_Void_LCDWriteCommand(0x80 + 0x54 + Copy_u8_Cell);
	}
}

void Lcd_Void_LCDCreateCustomChar(const u8* Copy_u8_ptr_ArrPattern,u8 Copy_u8_CharCode,u8 Copy_u8_Line,u8 Copy_u8_Cell) // Copy_u8_CharCode ----->place of starting CGRAM
{
    Lcd_Void_LCDWriteCommand(0x40 + (Copy_u8_CharCode * 8)); // Set CGRAM address for custom character

    for (u8 i = 0 ; i < 8 ; i++)
    {
        Lcd_Void_LCDWriteCharacter(Copy_u8_ptr_ArrPattern[i]);
    }
    Lcd_Void_LCDSetCursor(Copy_u8_Line,Copy_u8_Cell);
    Lcd_Void_LCDWriteCharacter(Copy_u8_CharCode);
}

void Lcd_Void_LCD_Shift(u8 Copy_u8_addshift)
{
	Lcd_Void_LCDWriteCommand(Copy_u8_addshift);
}


void Lcd_Void_Print(char* str, ...)
{
	va_list var_list;
	va_start(var_list, str);
	while(*str != '\0') {
		if (*str == '%') {
			str++;
			switch(*str) {
				case 'c':
                    Lcd_Void_LCDWriteCharacter((char)va_arg(var_list, int));
					break;
				case 'd':
                    Lcd_Void_LCDWriteNumber((int)va_arg(var_list, int));
					break;
				case 'u':
                    Lcd_Void_LCDWriteNumber((unsigned int)va_arg(var_list, unsigned int));
					break;
				case 'l':
                    Lcd_Void_LCDWriteNumber((long int)va_arg(var_list, long int));
					break;
				default:
					Lcd_Void_LCDWriteCharacter(*str);
					break;
			}
		}
		else {
			Lcd_Void_LCDWriteCharacter(*str);
		}
		str++;
	}
}
