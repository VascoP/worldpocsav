#include "main_header.h"

/*
*	Presents a field with a label, writes the input into string
*	Option: password - asks for confirmation and displays *'s instead (*'s not implemented yet)
*	---> EDIT: UPDATE IN ORDER TO RECEIVE MIN/MAX INPUT VALUES <---
*/
int inputField(char * label, char * string, int password)
{
	char check[11];

	clear();
	curs_set(1);
	refresh();

	do
	{
		printw("[3-10] letters\n\n");
		printw("%s: ", label);
		if(readString(string, password) == NULL)
		{
			curs_set(0);
			return -1;
		}
		strcpy(check, string);
		printw("\n\nConfirmation must match\n");
		printw("Confirm: ");
		string[0] = '\0';
		if(readString(string, password) == NULL)
		{
			curs_set(0);
			return -1;
		}
		clear();
		refresh();
	}
	while((strcmp(check, string) != 0) || strlen(string) < 3);

	clear();
	curs_set(0);
	refresh();
	return 0;
}

char * readString(char * string, int password)
{
	int y, x, c, i = 0;
	unsigned int asterisk = 0;

	getyx(stdscr, y, x);

	while((c = getch()) != ENTER_KEY) 
	{
		if(((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) && (i < 10))
		{
			string[i++] = c;
			string[i] = '\0';
			move(y, x);
			clrtoeol();
			refresh();
			if(password)
			{
				while(asterisk < strlen(string))
				{
					addch('*');
					asterisk++;
				}
				asterisk = 0;
			}
			else
				printw("%s", string);
		}
		if(c == KEY_BACKSPACE && i > 0)
		{
			i--;
			string[i] = '\0';
			move(y, x);
			clrtoeol();
			refresh();
			if(password)
			{
				while(asterisk < strlen(string))
				{
					addch('*');
					asterisk++;
				}
				asterisk = 0;
			}
			else
				printw("%s", string);
		}
		if(c == ESCAPE_KEY)
			return NULL;
	}
	return string;
}

