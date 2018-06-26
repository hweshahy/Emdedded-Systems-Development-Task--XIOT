/*
 * std_macros.h
 *
 * Created: 2/9/2018 10:37:46
 *  Author: Hussein
 */ 


#ifndef STD_MACROS_H_
#define STD_MACROS_H_
#include <avr/io.h>
#define F_CPU 8000000UL
#include <util/delay.h>
#include <avr/interrupt.h>

#define SETBIT(var,bit) var|=(1<<bit)//SETBIT(portf,3)=  portf|=1<<3
#define TOGBIT(var,bit) var^=(1<<bit)//SETBIT(portf,3)=  portf|=1<<3
#define CLRBIT(var,bit) var&=(~(1<<bit))//CLRBIT(portf,3)=  portf&=~(1<<3)
#define READBIT(VAR,BIT) ((VAR>>BIT)&1)//X=((Y>>BIT)&1))




#endif /* STD_MACROS_H_ */