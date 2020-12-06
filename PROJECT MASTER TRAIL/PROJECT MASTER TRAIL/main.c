/*
 * (MASTER)Ahmed Ashraf Fathy E19.c
 *
 * Created: 05/12/2020 02:16:23
 * Author : Buddha73
 */ 

#include <avr/io.h>
#include "Libs/UART/UART.h"
#include "Libs/SPI/SPI.h"
int main(void)
{
	UART_init();
	SPI_init(1);
	//char X= UART_Receive();
    while (1) 
    {
	char X= UART_Receive();
		 SPI_MASTER_SEND(X);
	 _delay_ms(100);
    }
}

