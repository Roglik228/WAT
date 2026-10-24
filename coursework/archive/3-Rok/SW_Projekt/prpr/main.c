#include <REGX52.H>

extern void LCD_Init();
extern void LCD_Cmd(unsigned char cmd);
extern void LCD_Data(unsigned char val);
extern void LCD_Goto(unsigned char row, unsigned char col);
extern void LCD_PrintPadded(unsigned char row, const char *buf, unsigned char len);

#define Window_Tap 1500
#define Line_Len 16
#define Total_Len 64

unsigned long g = 0;

void delay(unsigned char t)
	{
		unsigned char i, j;
		for(i = 0; i < t; i++)
		{
			for(j = 0; j < 123; j++) { }
			g++;
		}
	}

#define KBD_PORT P2

unsigned char tabC3[3] = {0xF7, 0xFB, 0xFD};

const char keymap_4x3[4][3] = {
	{'1','2','3'},
	{'4','5','6'},
	{'7','8','9'},
	{'*','0','#'}


};

char readKeyChar_4x3()
	{
		unsigned char c, r;
		unsigned char rowBits;

		KBD_PORT = 0xFF;

		for(c = 0; c < 3; c++)
			{
				KBD_PORT = tabC3[c];
				delay(1);
		
				rowBits = KBD_PORT & 0xF0;

				if(rowBits != 0xF0)
					{
						delay(5);
						rowBits = KBD_PORT & 0xF0;

						if(rowBits != 0xF0)
							{
								for(r = 0; r < 4; r++)
								{
									unsigned char mask = (unsigned char)(1 << (r + 4));

									if((rowBits & mask) == 0)
										{
											while((KBD_PORT & mask) == 0) { delay(1); }
											KBD_PORT = 0xFF;
											return keymap_4x3[r][c];
										}
								}
							}
					}
			}
			
			KBD_PORT = 0xFF;
			return 0;
	}

const char* tap_letters(char k)
	{
		switch(k)
			{
				case '2': return "2abc";
				case '3': return "3def";
				case '4': return "4ghi";
				case '5': return "5jkl";
				case '6': return "6mno";
				case '7': return "7pqrs";
				case '8': return "8tuv";
				case '9': return "9wxyz";
				case '0': return " ";
				case '1': return "1.,?!0";
				default:  return "";
			}
	}

unsigned char s_len(const char *s)
	{
		unsigned char n=0; while(*s++) n++; return n;
	}

char textbuf[Total_Len + 1];

unsigned char pos = 0; 
unsigned char editing = 0;
unsigned char lastKey = 0;
unsigned char tapIdx = 0;
unsigned long lastTapT = 0;

char upperMode = 0;

char apply_case(char ch)
	{
		if(upperMode && ch >= 'a' && ch <= 'z')
			return (char)(ch - 'a' + 'A');
		return ch;
	}

void clear_textbuf()
	{
		unsigned char i;
		for(i = 0; i < Total_Len + 1; i++)
			textbuf[i] = 0;
	}

void render()
	{
		LCD_PrintPadded(0, textbuf, Line_Len);
		LCD_PrintPadded(1, textbuf + 16, Line_Len);
		LCD_PrintPadded(2, textbuf + 32, Line_Len);
		LCD_PrintPadded(3, textbuf + 48, Line_Len);
	}

void commit_if_editing()
	{
		if(editing)
			{
				editing = 0;
				lastKey = 0;
				tapIdx  = 0;

				if(pos < Total_Len) pos++;

				if(pos >= Total_Len)
					{
						pos = 0;
						clear_textbuf();
						LCD_Cmd(0x01);
					}
			}
	}

void backspace()
	{
		if(editing)
			{
				textbuf[pos] = 0;
				editing = 0;
				lastKey = 0;
				tapIdx  = 0;
			}
		else
			{
				if(pos > 0)
					{
						pos--;
						textbuf[pos] = 0;
					}
			}
	}

void multitap_timeout_tick()
	{
		if(editing && (g - lastTapT > Window_Tap))
			{
				commit_if_editing();
				render();
			}
	}

void refresh_current_char_case()
	{
		if(editing)
			{
				const char *letters = tap_letters(lastKey);
				if(letters[0] != 0)
					textbuf[pos] = apply_case(letters[tapIdx]);
			}
	}

void multitap_handle_key(char k)
	{
		unsigned long now = g;

		if(k == '*')
			{ 
				backspace(); 
				render(); 
				return; 
			}

		if(k == '#')
			{
				upperMode = !upperMode;
				refresh_current_char_case();
				render();
				return;
			}

		if(editing && (now - lastTapT > Window_Tap))
			commit_if_editing();

		{
			const char *letters = tap_letters(k);
			unsigned char L = s_len(letters);
			if(L == 0) return;

			if(editing && k == lastKey && (now - lastTapT <= Window_Tap) && L > 1)
				{
					tapIdx++;
					if(tapIdx >= L) tapIdx = 0;
					textbuf[pos] = apply_case(letters[tapIdx]);
				}
			else
				{
					if(editing && k != lastKey) commit_if_editing();

					editing = 1;
					lastKey = k;
					tapIdx  = 0;
					textbuf[pos] = apply_case(letters[0]);
				}

			lastTapT = now;
			render();
		}
	}

void main()
	{
		clear_textbuf();

		LCD_Init();
		render();

		while(1)
			{
				char k = readKeyChar_4x3();
				if(k) multitap_handle_key(k);

				multitap_timeout_tick();
			}
	}