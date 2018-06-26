/*
 * Embedded_Task_XIOT.c
 *
 * Created: 6/25/2018 16:53:33
 * Author : Hussein
 */ 

//All included files are in the Embedded_Task_XIOT folder which contains the whole project if you want to test it on ATmega32
/*
I used the interrupt handler instead of polling as polling makes the micro-controller busy but the drawback of the interrupts,
they hang all the system and the best solution is using RTOS.
 */
//std_macros includes atmega32 libraries and some macros used for bitwise manipulation 
#include "std_macros.h"
//UART driver as i am using it as the serial interface
#include "uart.h"
//ADC Driver
#include "ADC1.h"
//lCD driver as i am using it as a monitor
#include "lcd_s.h"
//Control Signals
char Shared_resource_protection=0;
//Required Function
//returning a char to check the availability of the function as if it isn't used return 1 and if it is used return 0
char press_function();
//Timer 1 initialization (compare output mode with interrupts) to have 3 sec rate
void timer1_com_int_init();
//external interrupt (in falling and raising edge) Switch initialization
void int_init();

int main(void)
{	
	//initialization 
	ADC0_init();
	int_init();
	lcd_init();
	UART_init();
	timer1_com_int_init();
	//direction of LED as output
	SETBIT(DDRD,5);
	// enabling the interrupts
	sei();
	// writing the led status for the first time
	lcd_write_cmd(0xC0);
	lcd_write_txt("LED: OFF");
    /* Replace with your application code */
    while (1) 
    {	
		//another functions in the system
	}
}
//required function
char press_function(){
	
	char checking_global_interrupt=0;
	//checking if the function is in use or not
	if(Shared_resource_protection)//if it used it return zero
	{
		return 0;
	}
	
	//blocking other functions from enter using it at the same time
	Shared_resource_protection=1;
	
	//critical section disabling the interrupts
	if(READBIT(SREG,7))
	{
		cli();
	}
	else
	{
		checking_global_interrupt=1;
	}
	//reading the input to know if it is falling 
	if(READBIT(PIND,2))
	{
		//printing "pressed" on the monitor and toggling the led 
		lcd_write_cmd(0x80);//this command to put the courser of the LCD on the start of the first line
		lcd_write_txt("Pressed ");//printing "pressed"
		lcd_write_cmd(0xc5);//this command to put the courser of the LCD on the start of the second line
		TOGBIT(PORTD,5);
		
		//printing "on" or "off" on the monitor
		if(READBIT(PORTD,5))
		{
			lcd_write_txt("ON ");
		}
		else
		{
			lcd_write_txt("OFF");
		}

	}
	//in the raising edge
	else
	{
		lcd_write_cmd(0x80);//this command to put the courser of the LCD on the start of the first line
		lcd_write_txt("        ");//removing "pressed" from the LCD
	}
	//releasing the function for other calls
	Shared_resource_protection=0;
	
	//enabling the interrupt flag
	if(!checking_global_interrupt)
	{
	sei();
	}
		return 1;
}


//timer1 interrupt handler
ISR(TIMER1_COMPA_vect)
{
	int data=(ADC_read())*100/1024;//assume the ADC has 10 bits and temperature range from 0 to 100
	UART_tx(((char)data));
}

// external interrupt (push button) handler
ISR(INT0_vect)
{	
	
	press_function();
}

void int_init(){
	MCUCR|=(1<<ISC00);
	SETBIT(GICR,6);
}

void timer1_com_int_init(){
	SETBIT(TIMSK,4);
	OCR1A=23437;
	TCNT1=0;
	TCCR1B=0b1101;
}