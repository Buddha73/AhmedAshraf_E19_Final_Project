/*
* (SLAVE)Ahmed Ashraf Fathy E19.c
*
* Created: 05/12/2020 02:33:21
* Author : Buddha73
*/

#include <avr/io.h>
#include "Libs/SPI/SPI.h"
#include "Libs/LCD/LCD.h"



int main(void)
{
	DDRA = 0xff;
	SPI_init(0);
	LCD_init(4);
	
	while (1)
	{
		char y = SPI_SLAVE_RECEIVE();
		if ((y == 'a')|(y == 'A'))
		{
			setPinA(0);
			LCD_write_str4("ACT_1_ON");
		}
		else if ((y == 'b')|(y == 'B'))
		{
			resetPinA(0);
			LCD_write_str4("ACT_1_OFF");
		}
		else if ((y == 'c')|(y == 'C'))
		{
			setPinA(1);
			LCD_write_str4("ACT_2_ON");
		}
		else if ((y == 'd')|(y == 'D'))
		{
			resetPinA(1);
			LCD_write_str4("ACT_2_OFF");
		}
		else if ((y == 'e')|(y == 'E'))
		{
			setPinA(1);
			setPinA(0);
			LCD_write_str4("BOTH_ACT_ON");
		}
		else if ((y == 'f')|(y == 'F'))
		{
			resetPinA(1);
			resetPinA(0);
			LCD_write_str4("BOTH_ACT_OFF");
		}
		else
		{
			LCD_write_str4("Not_Defined");
		}
		_delay_ms(500);
		LCD_Clear4();
		
	}
}

