#include <REGX52.H>

#define LCD_RS P1_0
#define LCD_E P1_1
#define LCD_D4 P1_4
#define LCD_D5 P1_5
#define LCD_D6 P1_6
#define LCD_D7 P1_7

void delay_t(unsigned int t)
	{
		unsigned int i, j;
		for(i=0;i<t;i++)
		for(j=0;j<123;j++) { }
	}

void lcd_pulse()
	{
		LCD_E = 1;
		LCD_E = 0;
	}

void lcd_write4(unsigned char n)
	{
		LCD_D4 = (n & 0x01) ? 1 : 0;
		LCD_D5 = (n & 0x02) ? 1 : 0;
		LCD_D6 = (n & 0x04) ? 1 : 0;
		LCD_D7 = (n & 0x08) ? 1 : 0;
		lcd_pulse();
	}


void LCD_Cmd(unsigned char cmd)
	{
		LCD_RS = 0;
		lcd_write4(cmd >> 4);
		lcd_write4(cmd & 0x0F);
	
		if(cmd == 0x01 || cmd == 0x02)
			delay_t(2);
		else
		delay_t(1);
	}

void LCD_Data(unsigned char val)
	{
		LCD_RS = 1;
		lcd_write4(val >> 4);
		lcd_write4(val & 0x0F);
		delay_t(1);
	}

void LCD_Init()
	{
		LCD_RS = 0;
		LCD_E  = 0;
		delay_t(20);
	
		lcd_write4(0x03); 
		delay_t(5);
		lcd_write4(0x02); 
		delay_t(1);

		LCD_Cmd(0x28);
		LCD_Cmd(0x0C);
		LCD_Cmd(0x06);
		LCD_Cmd(0x01);
	}

void LCD_Goto(unsigned char row, unsigned char col)
	{
		unsigned char addr;
	
		switch(row)
			{
				case 0: addr = 0x00; break;
				case 1: addr = 0x40; break;
				case 2: addr = 0x10; break;
				default: addr = 0x50; break; 
			}

		LCD_Cmd(0x80 | (addr + col));
	}

void LCD_PrintPadded(unsigned char row, const char *buf, unsigned char len)
	{
		unsigned char i;
		LCD_Goto(row,0);

		for(i=0;i<len;i++)
		{
			char c = buf[i];
			if(c == 0) c = ' ';
			LCD_Data(c);
		}
	}