/*
 * LCD_config.h
 *

 */

#ifndef INC_LCD_CONFIG_H_
#define INC_LCD_CONFIG_H_

/**********************************************************************************************/
/*   SELECT MICROCONTROLERS PINS   */
/**********************************************************************************************/
#define LCD_D0_PIN                DIO_PORTA,DIO_PIN0
#define LCD_D1_PIN                DIO_PORTA,DIO_PIN1
#define LCD_D2_PIN                DIO_PORTA,DIO_PIN2
#define LCD_D3_PIN                DIO_PORTA,DIO_PIN3
#define LCD_D4_PIN                DIO_PORTB,DIO_PIN0
#define LCD_D5_PIN                DIO_PORTB,DIO_PIN1
#define LCD_D6_PIN                DIO_PORTB,DIO_PIN2
#define LCD_D7_PIN                DIO_PORTB,DIO_PIN4
#define LCD_RW_PIN                DIO_PORTA,DIO_PIN0
#define LCD_RS_PIN                DIO_PORTA,DIO_PIN3
#define LCD_EN_PIN                DIO_PORTA,DIO_PIN2

/**********************************************************************************************/
/*   LCD_MODE OPTIONS :  [ _4_BIT_MODE , _8_BIT_MODE ]   */
/**********************************************************************************************/
#define LCD_MODE           _4_BIT_MODE

#endif /* INC_LCD_CONFIG_H_ */
