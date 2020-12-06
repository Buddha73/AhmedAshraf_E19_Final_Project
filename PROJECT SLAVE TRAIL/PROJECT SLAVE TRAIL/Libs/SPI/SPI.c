/*
 * SPI.c
 *
 * Created: 04/12/2020 10:48:57
 * Author : Buddha73
 */
#define F_CPU 16000000UL
#include <stdlib.h>
#include <avr/io.h>
#include <util/delay.h>
//Define
#define SS   4
#define SCK  7
#define MOSI 5
#define MISO 6
//MASTER/SLAVE:
#define SPI_Master 1
#define SPI_Slave  0
void SPI_init(int mode);
//MASTER
void SPI_MASTER_SEND (char data);
void SPI_MASTER_SEND_STR(char* str);
void SPI_MASTER_SEND_NUM(int num);
//DORD
#define SPI_MSB 0
#define SPI_LSB 1
//PRESCALER
#define SPI_PS_4     0
#define SPI_PS_16    1
#define SPI_PS_64    2
#define SPI_PS_128   3
#define SPI_PS_2     4
#define SPI_PS_8     5
#define SPI_PS_32    6
#define SPI_PS_2X64  7
//SLAVE
char SPI_SLAVE_RECEIVE ();
//VOID

//VOID
void SPI_init(int mode)
{
	//SPI CONTROL REGISTER
if(mode == SPI_Master)
{
	DDRB |= (1<<SS)|(1<<MOSI)|(1<<SCK);
	SPCR |= (1<<MSTR);
}

else
{
	DDRB|= (1<<MISO);
}
	SPCR |= (1<<SPE)|(1<<SPR0)|(1<<SPR1);
}
//MASTER
void SPI_MASTER_SEND (char data)
{
	SPDR = data;
	while(!(SPDR &(1<<SPIF)));
}
void SPI_MASTER_SEND_STR(char* str)
{
	for(int i=0;str[i]!='\0';i++)
	{
		SPI_MASTER_SEND(str[i]);
	}
}
void SPI_MASTER_SEND_NUM(int num)
{
	char str[10];
	itoa (num,str,10);
	SPI_MASTER_SEND_STR(str);
}
char SPI_SLAVE_RECEIVE()
{
	while (!(SPDR &(1<<SPIF)));

	return SPDR;
}
