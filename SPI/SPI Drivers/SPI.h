/*
 * SPI.h
 *
 * Created: 2/9/2020 9:32:06 PM
 *  Author: A_ayman
 */ 


#ifndef SPI_H_
#define SPI_H_

#include "gpio.h"
#include "SPI_CFG.h"


typedef enum En_SPI_MODE_t{
	SPI_SLAVE_MODE=50,SPI_MASTER_MODE=0x40
}En_SPI_MODE_t;


typedef enum En_SPI_DATA_MODE_t{
	SPI_SAMPLE_RISING=0x00,SPI_SETUP_RISING=0x04,SPI_SAMPLE_FALLING=0x08,SPI_SETUP_FALLING=0X0C
}En_SPI_DATA_MODE_t;

typedef enum En_SPI_CLOCK_SELECT_t{
	SPI_FOSC_4=0x00,SPI_FOSC_16=0x01, SPI_FOSC_64=0X02 ,SPI_FOSC_128=0X03
}En_SPI_CLOCK_SELECT_t;

typedef enum En_SPI_Interrupt_t{
  SPI_INTERRUPT_DISABLE=0x00,SPI_INTERRUPT_ENABLE=0x80
}En_SPI_Interrupt_t;

typedef enum En_SPI_Data_Order_t{
  SPI_LSP_FIRST=0x20,SPI_MSB_FIRST=0x00
}En_SPI_Data_Order_t;






void SPI_Init (En_SPI_MODE_t SPI_MODE,En_SPI_DATA_MODE_t DATA_MODE,En_SPI_CLOCK_SELECT_t CLOCK_SELECT,En_SPI_Data_Order_t Data_Order,En_SPI_Interrupt_t SPI_Interrupt );
// void SPI_Enable (void);
// void SPI_Disable (void);
void SPI_SEND (uint8_t data);
uint8_t SPI_Rec (void);
void SPI_MASTER_CFG (void);
void SPI_SLAVE_CFG (void);


#endif /* SPI_H_ */