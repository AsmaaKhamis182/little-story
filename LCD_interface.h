/*
 * LCD_interface.h
 *

 */

#ifndef INC_LCD_INTERFACE_H_
#define INC_LCD_INTERFACE_H_

/**********************************************************************************************/
/*   INCLUDES   */
/**********************************************************************************************/
#include "STD_TYPES.h"
#include "DIO_interface.h"
#include <util/delay.h>


/**********************************************************************************************/
/*   PROTOTYPES   */
/**********************************************************************************************/
void Lcd_Void_LCDInit(void);
void Lcd_Void_LCDWriteCharacter(u8 Copy_U8_Character);
void Lcd_Void_LCDWriteCommand(u8 Copy_U8_Command);
void Lcd_Void_LCDWriteString(u8* Copy_U8_Ptr);
void Lcd_Void_LCDClear(void);
void Lcd_Void_LCDWriteNumber(s32 Copy_S32_Number);
void Lcd_Void_LCDGoTo(u8 Copy_U8_Row,u8 Copy_U8_Col);
void Lcd_Void_LCDWriteBinary(u8 Copy_u8_Number);
void Lcd_Void_LCDWriteHex(u8 Copy_u8_Number);
void Lcd_Void_LCDWriteNumber_4D(u16 Copy_u8_Number);
void Lcd_Void_LCDSetCursor(u8 Copy_u8_Line,u8 Copy_u8_Cell);
void Lcd_Void_LCDCreateCustomChar(const u8* Copy_u8_ptr_ArrPattern,u8 Copy_u8_CharCode,u8 Copy_u8_Line,u8 Copy_u8_Cell);
void Lcd_Void_LCD_Shift(u8 Copy_u8_addshift);
void Lcd_Void_Print(char* str, ...);

#endif /* INC_LCD_INTERFACE_H_ */
