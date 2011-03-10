#include "main_header.h"

/*
*	Presents a field with a label, writes the input into string
*	Option: password - asks for confirmation and displays *'s instead (*'s not implemented yet)
*	---> EDIT: UPDATE IN ORDER TO RECEIVE MIN/MAX INPUT VALUES <---
*/
int inputField(char * label, char * string, int password, int confirm)
{
	char check[11];
	WINDOW * winField;

	winField = newwin(3, 20, 2, 1);
	keypad(winField, TRUE);

	clear();
	curs_set(1);
	refresh();
	box(winField, 0, 0);
	wrefresh(winField);

	if(confirm == 1)
	{
		do
		{
			mvprintw(1, 2, "Register\n");
			mvwprintw(winField, 1, 1, "%s: ", label);
			wclrtoeol(winField);
			box(winField, 0, 0);
			refresh();	
			if(readString(string, password, winField) == NULL)
			{
				curs_set(0);
				clear();
				refresh();
				return -1;
			}
			strcpy(check, string);
			mvprintw(1, 2, "Confirmation must match\n");
			mvwprintw(winField, 1, 1, "%s: ", label);
			wclrtoeol(winField);
			box(winField, 0, 0);
			refresh();
			string[0] = '\0';
			if(readString(string, password, winField) == NULL)
			{
				curs_set(0);
				clear();
				refresh();
				return -1;
			}
			clear();
			wrefresh(winField);
		}
		while((strcmp(check, string) != 0) || strlen(string) < 3);
	}
	else
	{
		mvprintw(1, 2, "Login\n");
		refresh();
		mvwprintw(winField, 1, 1, "%s: ", label);
		if(readString(string, password, winField) == NULL)
		{
			curs_set(0);
			clear();
			refresh();
			return -1;
		}
	}

	clear();
	curs_set(0);
	refresh();
	return 0;
}

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

