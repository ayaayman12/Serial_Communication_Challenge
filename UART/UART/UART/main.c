/*
 * UART.c
 *
 * Created: 2/8/2020 7:10:19 PM
 * Author : A_ayman
 */ 

#include "gpio.h"
#include "USART.h"
#include "interrupts.h"
#include "led.h"
#include <util/delay.h>


int main(void)
{
	 uint8_t rec_data=0;
	 Led_Init(LED_0);
	 Led_Off(LED_0);
    USART_Init(USART_ASYNC_MODE,USART_RX_TX_Enable,USART_8BIT_DATA,USART_PARITY_DIS,USART_RISING_TRANSMIT,USART_1_STOP_BIT,USART_Interrupt_Disabl,USART_9600_BAUD_RATE);
	 UART_Send_String(" Welcome... \n");
	 UART_Send_String(" Please Enter o for Led on \n and other character for led off\n");

    while (1) 
    {
		  rec_data=USART_Receive_POLLING();
		  _delay_ms(100);
	    if(rec_data=='o')
	    {
		    Led_On(LED_0);
	    }
	    else
	    {
		    Led_Off(LED_0);
	    }
	    
    }
}

