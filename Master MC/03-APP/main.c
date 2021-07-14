

#include "BIT_MATH.h"
#include "STD_TYPES.h"
#include "Dio_Interface.h"
#include "Uart_Interface.h"
#include "Spi_Interface.h"
#define  F_CPU	16000000UL
#include "util/delay.h"


int main(void)
{
	
	// Configure UART RX and TX pins
	Dio_ConfigChannel(DIO_PORTD,DIO_CHANNEL0, INPUT);
	Dio_ConfigChannel(DIO_PORTD,DIO_CHANNEL1, OUTPUT);
	
	// Initiate UART
    UART_Init(UART_BAUDRATE_9600);
	
	// Initiate Master SPI
	Spi_MasterInit();
	
	
	u8 BT_Data;
	
    while (1) 
    {
		// Date Received from BT/Virtual Terminal
		BT_Data = UART_ReceiveChr();
		
		// Data sent by Master SPI
		Spi_MasterWrite(BT_Data);
		
		 _delay_ms(100);
    }
}

