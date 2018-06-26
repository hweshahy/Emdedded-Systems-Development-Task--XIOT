/*
 * UART.h
 *
 * Created: 2/23/2018 12:57:23
 *  Author: Hussein
 */ 


#ifndef UART_H_
#define UART_H_

#include "std_macros.h"
volatile uint8_t data;
void UART_init();
uint8_t UART_rx();
void UART_tx(uint8_t data);
void UART_init_int_rx();

#endif /* UART_H_ */