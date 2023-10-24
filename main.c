/*
 * main.c
 *

 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"
#include "DIO_private.h"
#include "DIO_config.h"

#include "LCD_interface.h"
#include "LCD_private.h"
#include "LCD_config.h"

#include <util/delay.h>




int main(void)
{
	u8 person[] = {
	  0b00000000,
	  0b00001110,
	  0b00001110,
	  0b00000100,
	  0b00001110,
	  0b00010101,
	  0b00000100,
	  0b00001010
	};
	u8 dash[] = {
	  0b00000000,
	  0b00000000,
	  0b00000000,
	  0b00000000,
	  0b00000000,
	  0b00000000,
	  0b00011111,
	  0b00011111
	};
    Lcd_Void_LCDInit();

	while(1)
	{
	    Lcd_Void_LCDCreateCustomChar(person,0,0,0);
	    Lcd_Void_LCDCreateCustomChar(dash,1,0,1);
	    Lcd_Void_LCDCreateCustomChar(dash,1,0,2);
	    Lcd_Void_LCDCreateCustomChar(dash,1,0,3);
	    Lcd_Void_LCDCreateCustomChar(dash,1,0,4);
	    Lcd_Void_LCDCreateCustomChar(person,0,0,5);
	    //Lcd_Void_LCD_Shift();
		Lcd_Void_LCDSetCursor(2,0);
		Lcd_Void_LCDWriteString("\"");
		Lcd_Void_LCDSetCursor(2,1);
		Lcd_Void_LCDWriteString("stay in your place.");
		Lcd_Void_LCDSetCursor(3,1);
		Lcd_Void_LCDWriteString("Do not leave...");
		Lcd_Void_LCDSetCursor(3,16);
		Lcd_Void_LCDWriteString("\"");
	   for(u8 count = 5 ; count !=19 ; count++)
	   {

		 Lcd_Void_LCDCreateCustomChar(dash,1,0,count);
		 Lcd_Void_LCDCreateCustomChar(person,0,0,count+1);
		 _delay_ms(500);
	  }
	   Lcd_Void_LCDClear();
	}

}






