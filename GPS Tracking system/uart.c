/******************************************************************************
 *
 * Module: UART
 *
 * File Name: uart.c
 *
 * Description: Source file for UART Module
 *
 * Author: Seif Emad
 *
 *******************************************************************************/

#include "uart.h"

 /******************** UART 5 **************************/
void UART5_init (void)
{
  SYSCTL_RCGCUART_REG |= (1<<UART5);          /*Enable UART0 CLK*/
  
  /* Enable clock for PORTE and allow time for clock to start*/ 
  volatile unsigned long delay = 0;
  SYSCTL_REGCGC2_REG |= 0x00010000;
  delay = SYSCTL_REGCGC2_REG;
  
  UART5_CTL_REG = 0;         /*Disable UART0*/
  
  /* Values for Baud Rate*/
  UART5_IBRD_REG = BaudRateI;
  UART5_FBRD_REG = BaudRateF;
  
  /*********************** UARTLCRH Descreption *************
  * Disable Parity by clear bit 1 ,2, 7
  * Word lenth 8 bits
  * One stop bit is transmitted
  * FIFO Enable Buffer
  ***********************************************************/
  UART5_CC_REG = 0;  // select system clock 
  UART5_LCRH_REG = 0x60;
  UART5_LCRH_REG |= (1<<4);
  
  UART5_CTL_REG = 0x301;            /*Enable UART0*/
  
  /************************ GPIO configure *******************
  * Disable Analog on PA0 , PA1
  * Enable alternative function on PA0 , PA1 
  * Set PMCx bits for PA0 , PA1 by 1 
  * Set PA0 RX as input 
  * Set PA1 RT as output
  * Enable Digital I/O on PA0 , PA1 
  ***********************************************************/
  GPIO_PORTE_AMSEL_REG = 0;
  GPIO_PORTE_AFSEL_REG |= 0x30;
  GPIO_PORTE_PCTL_REG  |= 0x00110000;
  GPIO_PORTE_DEN_REG   |= 0x30;
}


void UART5_SendByte (const uint8 data)
{
	
        while(UART5_FR_REG & 0x20 != 0) {};
	UART5_DR_REG = data ; 	
}


uint8 UART5_ReceiveByte (void)
{
        
        while(UART5_FR_REG & (1<<4)) {};
	return (uint8)UART5_DR_REG ; 
}



void UART0_init (void)
{
  SYSCTL_RCGCUART_REG |= (1<<UART0);          /*Enable UART0 CLK*/
  
  /* Enable clock for PORTE and allow time for clock to start*/ 
  volatile unsigned long delay = 0;
  SYSCTL_REGCGC2_REG |= 0x00000001;
  delay = SYSCTL_REGCGC2_REG;
  
  UART5_CTL_REG = 0;         /*Disable UART0*/
  
  /* Values for Baud Rate*/
  UART0_IBRD_REG = BaudRateI;
  UART0_FBRD_REG = BaudRateF;
  
  /*********************** UARTLCRH Descreption *************
  * Disable Parity by clear bit 1 ,2, 7
  * Word lenth 8 bits
  * One stop bit is transmitted
  * FIFO Enable Buffer
  ***********************************************************/
  //UART0_CC_REG = 0;  // select system clock 
  UART0_LCRH_REG = 0x60;
  UART0_LCRH_REG |= (1<<4);
  
  UART5_CTL_REG = 0x301;            /*Enable UART0*/
  
  /************************ GPIO configure *******************
  * Disable Analog on PA0 , PA1
  * Enable alternative function on PA0 , PA1 
  * Set PMCx bits for PA0 , PA1 by 1 
  * Set PA0 RX as input 
  * Set PA1 RT as output
  * Enable Digital I/O on PA0 , PA1 
  ***********************************************************/
  GPIO_PORTA_AMSEL_REG = 0;
  GPIO_PORTA_AFSEL_REG |= 0x03;
  GPIO_PORTA_PCTL_REG  |= 0x000000011;
  GPIO_PORTA_DEN_REG   |= 0x03;
}

void UART0_SendByte (const uint8 data)
{
	
        while(UART0_FR_REG & 0x20 != 0) {};
	UART0_DR_REG = data ; 	
}


uint8 UART0_ReceiveByte (void)
{
        
        while(UART0_FR_REG & (1<<4)) {};
	return (uint8)UART0_DR_REG ; 
}




