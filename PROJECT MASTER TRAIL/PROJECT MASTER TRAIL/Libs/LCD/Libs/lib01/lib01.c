#include "lib01.h"
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
void Toggle PinA (int PinNo)
{
PortA ^= (1<<PinNo);
}
void Toggle PinB (int PinNo)
{
PortB ^= (1<<PinNo);
}
void Toggle PinC (int PinNo)
{
PortC ^= (1<<PinNo);
}
void Toggle PinD (int PinNo)
{
PortD ^= (1<<PinNo);
}
void setPortA (char data)
{
    PortA = data;
}
void setPortB (char data)
{
    PortB = data;
}
void setPortC (char data)
{
    PortC = data;
}
void setPortD (char data)
{
    PortD = data;
}
void DDRX (char PortX)
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
