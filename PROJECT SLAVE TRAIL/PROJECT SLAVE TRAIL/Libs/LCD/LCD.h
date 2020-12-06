/*
* LCD.c
*
* Created: 27/10/2020 17:06:12
* Author : Buddha73
*/


#include <avr/io.h>
#include "Libs/lib01/lib01.h"
#include <stdlib.h>
//VOID
#define RS   0
#define RW   1
#define EN   2
#define Ctrl          PORTC
#define Ctrl_Dir      DDRC
#define LCD_Data      PORTC
#define LCD_Data_Dir DDRC
//VOID
void LCD_init(int); //initiate driver
// 8bits mode.
void LCD_cmd(char cmd);
void LCD_Clear();
void LCD_write(char);
void LCD_goto_xy(int,int);
void LCD_write_str(char* str);
void LCD_write_num(unsigned int);
void LCD_goto_2ndL();
void LCD_goto_1stL();
// 4bits mode.
void LCD_cmd4(char cmd);
void LCD_Clear4();
void LCD_write4(char);
void LCD_goto_xy4(int,int);
void LCD_write_str4(char* str);
void LCD_write_num4(unsigned int);
void LCD_goto_2ndL4();
void LCD_goto_1stL4();
//VOID
/*int main(void)
{
		char x= 'A';
	LCD_init(4);

	
	while(1)
	{
	_delay_ms(100);
	LCD_write4('A');
	x++;
	}
	setPinC(0);
	resetPinC(1);
	char x='A';
	char y=100;
	char z= '1';
	LCD_init(4);
	_delay_ms(10);
	LCD_goto_xy4(0,4);
	LCD_write_str4("Hi_Ahmed.");
	while (1)
	{

		_delay_ms(100);
		LCD_Clear4();
		LCD_goto_xy4(0,1);
		LCD_write_str4("X = ");
		LCD_write4(x);
		x++;
		LCD_goto_xy4(0,7);
		LCD_write_str4("Y = ");
		LCD_write_num4(y);
		_delay_ms(200);
		LCD_Clear4();
		y++;
		_delay_ms(200);
		LCD_Clear4();
		LCD_goto_xy4(0,0);
		LCD_write4(z);
		z++;
		_delay_ms(500);
		TogglePinC(0);
		TogglePinC(1);
	}
}*/
//VOID..
void LCD_init(int mode)
{
	// Data Direction,

	//Data Mode 4-bits mode.
	if (mode == 4)
	{
		LCD_Data_Dir|=0xf0;
		Ctrl_Dir |= (1<<RS)|(1<<EN)|(1<<RW);
		LCD_cmd(0x28);//4-bits mode.
		_delay_ms(1);
		LCD_cmd4(0x01);// make clear LCD
		_delay_ms(1);
		LCD_cmd4(0x02);// return home
		_delay_ms(1);
		LCD_cmd4(0x06);// make increment in cursor
		_delay_ms(1);
		LCD_cmd4(0x80);// “8” go to first line and “0” is for 0th position
		_delay_ms(1);
		LCD_cmd4(0x0c);
		_delay_ms(100);
	}
	//Data 8-bits mode.
	else
	{
		LCD_Data_Dir=0xff;
		Ctrl_Dir |= (1<<RS)|(1<<EN);
		LCD_cmd(0x38);// 8-bits(1byte) mode.,initialization in 8bit mode of 16X2 LCD
		_delay_ms(1);
		LCD_cmd(0x01);// make clear LCD
		_delay_ms(1);
		LCD_cmd(0x02);// return home
		_delay_ms(1);
		LCD_cmd(0x06);// make increment in cursor
		_delay_ms(1);
		LCD_cmd(0x80);// “8” go to first line and “0” is for 0th position
		_delay_ms(1);
		LCD_cmd(0x0c);
		_delay_ms(100);
	}
} 
//8bits mode.
void LCD_cmd(char cmd) //setpin exist.
{
	resetPinA(RS);  //Access to Command Register.
	LCD_Data = cmd;
	setPinC(EN);    //Rising Edge.
	_delay_ms(100); // Pulse Duration.
	resetPinA(EN);  //Falling Edge.
}
void LCD_write(char data)//setpin exist.
{
	LCD_Data = data;
	Ctrl |= (1<<RS);
	
	setPinA(EN);    //Rising Edge.
	_delay_ms(10); // Pulse Duration.
	resetPinA(EN);  //Falling Edge.
}
void LCD_write_str(char* str)
{
	for (int i=0;str[i] != '\0';i++){
	LCD_write(str[i]);}
	/*Ctrl |=(1<<RS);
	Ctrl |=(1<<EN);
	_delay_ms(100);
	Ctrl &=~ (1<<EN);
	
	setPinA(EN);    //Rising Edge.
	_delay_ms(100); // Pulse Duration.
	resetPinA(EN);  //Falling Edge.*/
}
void LCD_Clear()
{
	_delay_ms(1);

	LCD_cmd(0x01);          // make clear LCD

	_delay_ms(1);
}
void LCD_write_num(unsigned int num)
{
	char strnum[8];
	itoa(num, strnum,10);
	LCD_write_str(strnum);
}
void LCD_goto_2ndL()
{
	LCD_cmd(0xC0);
}
void LCD_goto_1stL()
{
	LCD_cmd(0x80);
}
void LCD_goto_xy(int row, int col)
{
	if (row == 0 && col <16 )
	{
		LCD_goto_1stL();
		LCD_cmd(0x80|(col));
	}
	else if (row == 1 && col <16 )
	{
		LCD_cmd(0xC0|(col));
	}
	else
	{
		LCD_Clear();
		//	# warning "Not a Valid Row."
		LCD_write_str("Wrong Dimensions!!... ");
		_delay_ms(9999999999999990);
		LCD_Clear();
	}

}
//4bits mode.
void LCD_cmd4(char cmd)//setpin exist.
{
	resetPinC(RS);  //Access to Command Register.
	LCD_Data &= 0x0F;
	LCD_Data |= (0xf0&cmd);
	setPinC(EN);    //Rising Edge.
	_delay_ms(100); // Pulse Duration.
	resetPinC(EN);  //Falling Edge.
	_delay_ms(1);
	// second nib.
	LCD_Data &= 0x0F;
	LCD_Data |= (cmd<<4);
	setPinC(EN);    //Rising Edge.
	_delay_ms(100); // Pulse Duration.
	resetPinC(EN);  //Falling Edge.
}
void LCD_write4(char data)//setpin exist.
{
	LCD_Data = data;
	Ctrl |= (1<<RS);
	LCD_Data &= 0x0F;
	LCD_Data |= (0xf0&data);
	setPinC(EN);    //Rising Edge.
	_delay_ms(100); // Pulse Duration.
	resetPinC(EN);  //Falling Edge.
	_delay_ms(1);
	// second nib.
	LCD_Data &= 0x0F;
	LCD_Data |= (data<<4);
	setPinC(EN);    //Rising Edge.
	_delay_ms(100); // Pulse Duration.
	resetPinC(EN);  //Falling Edge.

}
void LCD_write_str4(char* str)
{
	for (int i=0;str[i] != '\0';i++)
	{
	LCD_write4(str[i]);}
}
void LCD_Clear4()
{
	_delay_ms(1);

	LCD_cmd4(0x01);          // make clear LCD

	_delay_ms(1);
}
void LCD_write_num4(unsigned int num)
{
	char strnum[8];
	itoa(num, strnum,10);
	LCD_write_str4(strnum);
}
void LCD_goto_2ndL4()
{
	LCD_cmd4(0xC0);
}
void LCD_goto_1stL4()
{
	LCD_cmd4(0x80);
}
void LCD_goto_xy4(int row, int col)
{
	if (row == 0 && col <16 )
	{
		LCD_cmd4(0x80|(col));
	}
	else if (row == 1 && col <16 )
	{
		LCD_cmd4(0xC0|(col));
	}
	else
	{
		LCD_Clear4();
		//	# warning "Not a Valid Row."
		LCD_write_str4("Wrong Dimensions!!... ");
		_delay_ms(9999999999999990);
		LCD_Clear4();
	}

}
