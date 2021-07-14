
#include "BIT_MATH.h"
#include "STD_TYPES.h"
#include "Dio_Interface.h"
#include "Spi_Interface.h"
#define  F_CPU	16000000UL
#include "util/delay.h"

#define Act1_ON  (49) // "1"
#define Act1_OFF  (48) // "0"
#define Act2_ON  (72) // "H"
#define Act2_OFF  (76) // "L"


int main(void)
{

	// Two LEDs
	Dio_ConfigChannel(DIO_PORTC,DIO_CHANNEL2, OUTPUT);
	Dio_ConfigChannel(DIO_PORTC,DIO_CHANNEL7, OUTPUT);

	// Initiate Slave SPI
	Spi_SlaveInit();
	
	u8 ReciData=0;
	while (1)
	{
	    // Get data from the Master MC
		ReciData = Spi_SlaveRead();
		
		// Turn on the LEDs based on the received data
		switch (ReciData)
		{
			 case Act1_ON:
				Dio_WriteChannel(DIO_PORTC ,DIO_CHANNEL2 , STD_HIGH);
				break;
			case Act1_OFF:
				Dio_WriteChannel(DIO_PORTC ,DIO_CHANNEL2 , STD_LOW);
				break;
			 case Act2_ON:
				Dio_WriteChannel(DIO_PORTC ,DIO_CHANNEL7 , STD_HIGH);
				break;
			 case Act2_OFF:
				Dio_WriteChannel(DIO_PORTC ,DIO_CHANNEL7 , STD_LOW);
				break;		
		}
		_delay_ms(100);
	}
}

