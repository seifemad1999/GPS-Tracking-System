 /******************************************************************************
 *
 * Module: LCD
 *
 * File Name: lcd.c
 *
 * Description: Source file for the LCD driver
 *
 * Author: seif eldeen amr
 *
 *******************************************************************************/

#include "lcd.h"
#include <stdlib.h>
#include "tm4c123gh6pm_registers.h"
/*******************************************************************************
 *                      Functions Definitions                                  *
 *******************************************************************************/
#define NUMBER_OF_ITERATIONS_PER_ONE_MILI_SECOND 762

void _delay_ms(unsigned long long n)
{
    volatile unsigned long long count = 0;
    while(count++ < (NUMBER_OF_ITERATIONS_PER_ONE_MILI_SECOND * n) );
}
void LCD_init(void)
{
	
	
	LCD_sendCommand(TWO_LINE_LCD_Eight_BIT_MODE);
	
	LCD_sendCommand(CURSOR_OFF); 
	
	LCD_sendCommand(CLEAR_COMMAND); 
}

void LCD_sendCommand(uint8 command)
{
	
	GPIO_PORTE_DATA_REG&= ~(1<<0);
	
	GPIO_PORTE_DATA_REG&= ~(1<<1);

	_delay_ms(1); 
	
	GPIO_PORTE_DATA_REG|= (1<<2);
	_delay_ms(1); 
	
	GPIO_PORTB_DATA_REG=command;
	_delay_ms(1); 
	
	GPIO_PORTE_DATA_REG&= ~(1<<2);
	_delay_ms(1); 
}

void LCD_displayCharacter(uint8 data)
{
	
	GPIO_PORTE_DATA_REG|= (1<<0);


	
	GPIO_PORTE_DATA_REG&= ~(1<<1);

	_delay_ms(1); 
	
	GPIO_PORTE_DATA_REG|= (1<<2);
	_delay_ms(1); 

	
	GPIO_PORTB_DATA_REG=data;
	_delay_ms(1); 
	
	GPIO_PORTE_DATA_REG&= ~(1<<2);
	_delay_ms(1); 
/*
void LCD_floatToString(float data)
{
   char buff[16]; /* String to hold th
   gcvt((double)data,8,buff); /* 10 for decimal 
   LCD_displayString(buff);
}
*/
void LCD_displayString(const char *Str)
{
	uint8 i = 0;
	while(Str[i] != '\0')
	{
		LCD_displayCharacter(Str[i]);
		i++;
	}
	
}

void LCD_goToRowColumn(uint8 row,uint8 col)
{
	uint8 Address;
	
	/* first of all calculate the required address */
	switch(row)
	{
		case 0:
				Address=col;
				break;
		case 1:
				Address=col+0x40;
				break;
		case 2:
				Address=col+0x10;
				break;
		case 3:
				Address=col+0x50;
				break;
	}					
	/* to write to a specific address in the LCD 
	 * we need to apply the corresponding command 0b10000000+Address */
	LCD_sendCommand(Address | SET_CURSOR_LOCATION); 
}

void LCD_displayStringRowColumn(uint8 row,uint8 col,const char *Str)
{
	LCD_goToRowColumn(row,col); /* go to to the required LCD position */
	LCD_displayString(Str); /* display the string */
}

void LCD_intgerToString(int data)
{
   char buff[16]; /* String to hold the ascii result */
   itoa(data,buff,10); /* 10 for decimal */
   LCD_displayString(buff);
}

void LCD_clearScreen(void)
{
	LCD_sendCommand(CLEAR_COMMAND); //clear display 
}
