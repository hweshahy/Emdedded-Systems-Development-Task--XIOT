/*
 * ADC1.c
 *
 * Created: 2/10/2018 13:22:38
 *  Author: Hussein
 */ 

#include "ADC1.h"
void ADC0_init(){
	ADMUX=0x80;
	ADCSRA|=(1<<ADEN)|0x07;
}
void ADC1_init(){
	
	ADMUX=0x81;
	ADCSRA|=(1<<ADEN)|0x07;

}
uint32_t ADC_read(){
	
	ADCSRA |= (1<<ADSC);
	while((ADCSRA & (1<<ADIF)));
	return (ADCL | (ADCH << 8));
}
