/*
 * SPI.c
 *
 * Created: 2/9/2020 9:31:43 PM
 *  Author: A_ayman
 */ 

#include "SPI.h"
void SPI_Init (En_SPI_MODE_t SPI_MODE,En_SPI_DATA_MODE_t DATA_MODE,En_SPI_CLOCK_SELECT_t CLOCK_SELECT,En_SPI_Data_Order_t Data_Order,En_SPI_Interrupt_t SPI_Interrupt )
{
	 
	 SPCR=0X00; // CLEAR REGISTER FIRST 
	 
	 switch(SPI_MODE)
	 {
		  case SPI_MASTER_MODE:
		  {  
			  SPI_MASTER_CFG ();
			  break;
		  }
		  case SPI_SLAVE_MODE:
		  {  
			  SPI_SLAVE_CFG ();
			  break;
		  }
		  default : break;
	 }
	 SPCR|= (SPI_MODE | DATA_MODE | CLOCK_SELECT | Data_Order | Data_Order);
}




// void SPI_Enable (void)
// {
	 // SPCR|=0x40; //SPI Enable, set spe bit;
// }

// void SPI_Disable (void)
// {
	// SPCR&=~(0x40); //SPI Enable, set spe bit;
// }

void SPI_SEND (uint8_t data)
{
	 SPDR=data;
	 while(!(SPSR & (1 << 7)));  // this bit is set when transfer is complete
}
uint8_t SPI_Rec (void)
{
	while(!(SPSR & (1 << SPIF)));  // this bit is set when transfer is complete
	return SPDR;
}



void SPI_MASTER_CFG (void)
{
	 gpioPinDirection(SPI_GPIO ,SPI_MOSI_BIT,OUTPUT);
	 gpioPinDirection(SPI_GPIO ,SPI_MISO_BIT,INPUT);
	 gpioPinDirection(SPI_GPIO ,SPI_SCK_BIT,OUTPUT);
	 gpioPinDirection(SPI_GPIO ,SPI_SS_BIT,OUTPUT);
	 
}

void SPI_SLAVE_CFG (void)
{
	gpioPinDirection(SPI_GPIO ,SPI_MOSI_BIT,INPUT);
	gpioPinDirection(SPI_GPIO ,SPI_MISO_BIT,OUTPUT);
	gpioPinDirection(SPI_GPIO ,SPI_SS_BIT,INPUT);
	gpioPinDirection(SPI_GPIO ,SPI_SCK_BIT,INPUT);
}
