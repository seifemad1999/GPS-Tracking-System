 /******************************************************************************
 *
 * Module: UART
 *
 * File Name: uart.h
 *
 * Description: Header file for the UART Module
 *
 * Author: Seif Emad
 *
 *******************************************************************************/

#ifndef UART_H_
#define UART_H_

#include "tm4c123gh6pm_registers.h"
#include "common_macros.h"
#include "std_types.h"

/*******************************************************************************
 *                      Preprocessor Macros                                    *
 *******************************************************************************/
#define UART5 5
#define UART2 2
#define UARTEN 0
#define TXFF 5
#define RXFF 6
#define RXFE 4
#define UARTWordLength 0x3   /* 8 bits */


/* UART Driver Baud Rate */
#define UART_BAUDRATE 9600
#define BaudRateI 104
#define BaudRateF 11

#ifndef F_CPU
#define F_CPU 16000000UL
#endif


/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/
void UART0_init (void);

void UART0_SendByte (const uint8 data);

uint8 UART0_ReceiveByte (void);

void UART0_SendString(const uint8 *Str);

void UART0_ReceiveString(uint8 *Str); // Receive until #

void UART2_init (void);

void UART2_SendByte (const uint8 data);

uint8 UART2_ReceiveByte (void);

void UART2_SendString(const uint8 *Str);

void UART2_ReceiveString(uint8 *Str); // Receive until #

#endif /* UART_H_ */
