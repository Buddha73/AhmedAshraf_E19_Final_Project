
#include <avr/io.h>
#include <util/delay.h> // to use Delay
void setPinA(int PinNo);
void setPinB(int PinNo);
void setPinC(int PinNo);
void setPinD(int PinNo);
void resetPinA(int PinNo);
void resetPinB(int PinNo);
void resetPinC(int PinNo);
void resetPinD(int PinNo);
int isPressedA(int PinNo);
int isPressedB(int PinNo);
int isPressedC(int PinNo);
int isPressedD(int PinNo);
void TogglePinA (int PinNo);
void TogglePinB (int PinNo);
void TogglePinC (int PinNo);
void TogglePinD (int PinNo);
void setPortA (char data);
void setPortB (char data);
void setPortC (char data);
void setPortD (char data);
//VOID
//#include "lib01.h"
void setPinA(int PinNo)
{
	PORTA |= (1<<PinNo);
}
void setPinB(int PinNo)
{
	PORTB |= (1<<PinNo);
}
void setPinC(int PinNo)
{
	PORTC |= (1<<PinNo);
}
void setPinD(int PinNo)
{
	PORTD |= (1<<PinNo);
}
void resetPinA(int PinNo)
{
	PORTA &=~ (1<<PinNo);
}
void resetPinB(int PinNo)
{
	PORTB &=~ (1<<PinNo);
}
void resetPinC(int PinNo)
{
	PORTC &=~ (1<<PinNo);
}
void resetPinD(int PinNo)
{
	PORTD &=~ (1<<PinNo);
}
int isPressedA(int PinNo)
{
	if (PINA & (1<<PinNo)){
	return 1;} //PORTA = 0xFF;
	else
	{
		return 0;
	}
}
int isPressedB(int PinNo)
{
	if (PINB & (1<<PinNo)){
	return 1;} //PORTB = 0xFF;
	else
	{
		return 0;
	}
}
int isPressedC(int PinNo)
{
	if (PINC & (1<<PinNo)){
	return 1;} //PORTC = 0xFF;
	else
	{
		return 0;
	}
}
int isPressedD(int PinNo)
{
	if (PIND & (1<<PinNo)){
		return 1;
	} //PORTD = 0xFF;
	else
	{
		return 0;
	}
}
void TogglePinA (int PinNo)
{
	PORTA ^= (1<<PinNo);
}
void TogglePinB (int PinNo)
{
	PORTB ^= (1<<PinNo);
}
void TogglePinC (int PinNo)
{
	PORTC ^= (1<<PinNo);
}
void TogglePinD (int PinNo)
{
	PORTD ^= (1<<PinNo);
}
void setPortA (char data)
{
	PORTA = data;
}
void setPortB (char data)
{
	PORTB = data;
}
void setPortC (char data)
{
	PORTC = data;
}
void setPortD (char data)
{
	PORTD = data;
}
/*void DDRX (char PortX)
{
	if (PortX == A1)
	{
		DDRA =0xff
	}
	else if (PortX == A0)
	{
		DDRA =0x00
	}
	else if (PortX == B1)
	{
		DDRB =0xff
	}
	else if (PortX == B0)
	{
		DDRB =0x00
	}
	else if (PortX == C1)
	{
		DDRC =0xff
	}
	else if (PortX == C0)
	{
		DDRC =0x00
	}
	else if (PortX == D1)
	{
		DDRD =0xff
	}
	else (PortX == D0)
	{
		DDRD =0x00
	}
}
*/