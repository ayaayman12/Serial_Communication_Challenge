/*
 * USART.c
 *
 * Created: 2/8/2020 7:10:49 PM
 *  Author: A_ayman
 */ 
#include "USART.h"
#include "led.h"
void USART_Init(En_USART_MODE_t USART_MODE, En_USART_RECEIVE_TRANSMIT_t USART_RX_TX, En_USART_CHAR_DATA_NUMBER_t CHAR_DATA_NUMBER,\
                En_USART_PARITY_MODE_t USART_PARITY, En_USART_CLOCK_POLARITY_t USART_CLOCK_POLARITY,En_USART_STOP_BIT_SELECT_t STOP_BIT_SELECT,\
					 En_USART_INTERRUPTS_t USART_INTERRUPTS,En_USART_BAUD_RATE_SELECT_t USART_BAUD_RATE_SELECT)

{
	 /* this bit must be cleared before writing at UBRR*/
	 UCSRC=0X00;
	 UCSRB=0x00;
	 UCSRB|=USART_RX_TX;
	 UCSRB|=USART_INTERRUPTS;
	 UBRRL= USART_BAUD_RATE_SELECT;
	 UBRRH =(USART_BAUD_RATE_SELECT>>8);
	 
	/* this bit must be cleared before writing at UCSRC*/
	 UCSRC|=(0x80);
	 UCSRC|=USART_MODE;
	 UCSRC|= USART_CLOCK_POLARITY;
	 UCSRC|=CHAR_DATA_NUMBER;
	 UCSRC|=STOP_BIT_SELECT;
	 UCSRC|=USART_PARITY;
   // UCSRC = 0x06;
	 //UCSRC&=~(0x80);

}



void USART_SEND_POLLING(uint8_t Data)
{
	 while (!(UCSRA&(1<<UDRE)));  //waiting for the transmit buffer (UDR) to be empty
	 UDR=Data;	 
}

uint8_t USART_Receive_POLLING(void)
{
	
   while (!(UCSRA&(1<<RXC)));  //waiting for the data to be received 
	return UDR;
	
}
void UART_Send_String(uint8_t* str)
{
	uint16_t i=0;
	while(str[i] != '\0')
	USART_SEND_POLLING(str[i++]);
}
void USART_SEND_NO_POLLING(uint8_t Data)
{
	UDR=Data;
}

uint8_t USART_Receive_NO_POLLING(void)
{
	
	return UDR;
	
}


