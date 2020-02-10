/*
 * USART.h
 *
 * Created: 2/8/2020 7:11:10 PM
 *  Author: A_ayman
 */ 


#ifndef USART_H_
#define USART_H_
#include "USART_CFG.h"
#include "registers.h"
#include "gpio.h"
#define F_cpu	16000000UL

typedef enum En_USART_MODE_t{
	USART_ASYNC_MODE=0x00,USART_SYNC_MODE=0x40
}En_USART_MODE_t;

typedef enum En_USART_PARITY_MODE_t{
	USART_PARITY_DIS=0x00,USART_PARITY_EVEN=0x20,USART_PARITY_ODD=0x30
}En_USART_PARITY_MODE_t;

typedef enum En_USART_CLOCK_POLARITY_t{
	USART_RISING_TRANSMIT=0x00,USART_FALLING_TRANSMIT=0x01
}En_USART_CLOCK_POLARITY_t;

typedef enum En_USART_CHAR_DATA_NUMBER_t{
	USART_5BIT_DATA=0x00,USART_6BIT_DATA=0x02,USART_7BIT_DATA=0x04,USART_8BIT_DATA=0x06
}En_USART_CHAR_DATA_NUMBER_t;

typedef enum En_USART_INTERRUPTS_t{
	USART_Interrupt_Disabl=0x00,USART_RX_Complete_Interrupt_Enable=0x80,USART_TX_Complete_Interrupt_Enable=0x40,USART_Data_Register_Empty_Interrupt_Enable=0x20
}En_USART_INTERRUPTS_t;

typedef enum En_USART_RECEIVE_TRANSMIT_t{
	USART_RX_TX_Enable=0x18,USART_RX_Enable=0x10,USART_TX_Enable=0x08
}En_USART_RECEIVE_TRANSMIT_t;

typedef enum En_USART_STOP_BIT_SELECT_t{
	USART_1_STOP_BIT=0x00,USART_2_STOP_BIT=0x08
}En_USART_STOP_BIT_SELECT_t;

/************************************************************************/
/** the values of this baud rate are only compatible with FOSC=16MHz and double speed mode is disabled  */                             
/************************************************************************/
typedef enum En_USART_BAUD_RATE_SELECT_t{
	USART_9600_BAUD_RATE=0x0067, USART_4800_BAUD_RATE=0x00Cf
}En_USART_BAUD_RATE_SELECT_t;


/************************************************************************/
/* functions Prototypes                                                                     */
/************************************************************************/
extern volatile uint8_t u_ret_data;

void USART_Init(En_USART_MODE_t USART_MODE, En_USART_RECEIVE_TRANSMIT_t USART_RX_TX, En_USART_CHAR_DATA_NUMBER_t CHAR_DATA_NUMBER,\
					 En_USART_PARITY_MODE_t USART_PARITY, En_USART_CLOCK_POLARITY_t USART_CLOCK_POLARITY,En_USART_STOP_BIT_SELECT_t STOP_BIT_SELECT,\
					 En_USART_INTERRUPTS_t USART_INTERRUPTS,En_USART_BAUD_RATE_SELECT_t USART_BAUD_RATE_SELECT);

void USART_SEND_POLLING(uint8_t Data);
uint8_t USART_Receive_POLLING(void);
void UART_Send_String(uint8_t* str);

#endif /* USART_H_ */