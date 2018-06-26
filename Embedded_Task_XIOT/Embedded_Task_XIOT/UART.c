/*
 * UART.c
 *
 * Created: 2/23/2018 12:57:50
 *  Author: Hussein
 */ 

#include "UART.h"
void UART_init(){
	UBRRL=51;
	UCSRB|=(1<<RXEN)|(1<<TXEN);
	UCSRC|=(1<<URSEL)|(1<<UCSZ1)|(1<<UCSZ0);
}

void UART_init_int_rx(){
	UBRRL=51;
	UCSRB|=(1<<RXEN)|(1<<TXEN)|(1<<RXCIE);
	UCSRC|=(1<<URSEL)|(1<<UCSZ1)|(1<<UCSZ0);
}
uint8_t UART_rx(){
	while(!(UCSRA&(1<<RXC)));
	return UDR;
}
void UART_tx(uint8_t data){
	while(!(UCSRA&(1<<UDRE)));
	UDR=data;
}

/*
ISR(USART_RXC_vect){
	data=UDR;
}*/