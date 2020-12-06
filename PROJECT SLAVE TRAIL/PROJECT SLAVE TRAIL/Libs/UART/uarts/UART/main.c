/*
 * UART.c
 *
 * Created: 04/12/2020 10:33:49
 * Author : Buddha73
 */ 

#include <avr/io.h>
#include <stdlib.h>
//MASTER
void UART_init();
void UART_Send_Char(char data);
void UART_Send_STR(char* str);
void UART_Send_NUM(int num);
//SLAVE
char UART_Receive();
//VOID
/*int main(void)
{
	UART_init();
	
	UART_Send_STR(" WELCOME UART\r ");
	UART_Send_NUM(100);
	char x = UART_Receive();
	UART_Send_STR("\r");
	UART_Send_Char(x);
	while (1)
	{
	}
}*/
//VOID
void UART_init()
{
	UCSRB |=(1<<TXEN) |(1<<RXEN);
	UBRRL =103;
}
void UART_Send_Char(char data)
{
	//pooling........
	while(!(UCSRA &(1<<UDRE)));
	UDR =data;
}
void UART_Send_STR(char* str)
{
	for(int i=0 ;str[i]!='\0';i++){
	UART_Send_Char(str[i]);}
}
void UART_Send_NUM(int num)
{
	char str[10];
	itoa (num,str,10);
	UART_Send_STR(str);
}
char UART_Receive()
{
	while (!(UCSRA & (1<<RXC)));
	return UDR;
}