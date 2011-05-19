#include "main_header.h"
/*
*	Reads a string from the keyboard, only accepts letters, max size 10 (add parameter to add functionality)
*	Enter key submits string, Escape key exits and returns NULL
*	If password argument is 1, asterisks are echoed instead of pressed characters
*	Returns a string 
*/
char * readString(char * string, int password, WINDOW * win)
{
	int y, x, c, i = 0;
	unsigned int asterisk = 0;

	getyx(win, y, x);

	while((c = wgetch(win)) != ENTER_KEY) 
	{
		if(((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) && (i < 10))
		{
			string[i++] = c;
			string[i] = '\0';
			wmove(win, y, x);
			wclrtoeol(win);
			wrefresh(win);
			if(password)
			{
				while(asterisk < strlen(string))
				{
					waddch(win, '*');
					asterisk++;
				}
				asterisk = 0;
			}
			else
				wprintw(win, "%s", string);

			box(win, 0, 0);
			wrefresh(win);
		}
		if(c == KEY_BACKSPACE && i > 0)
		{
			i--;
			string[i] = '\0';
			wmove(win, y, x);
			wclrtoeol(win);
			wrefresh(win);
			if(password)
			{
				while(asterisk < strlen(string))
				{
					waddch(win, '*');
					asterisk++;
				}
				asterisk = 0;
			}
			else
				wprintw(win, "%s", string);

			box(win, 0, 0);
			wrefresh(win);
		}
		if(c == ESCAPE_KEY)
			return NULL;
	}
	return string;
}


