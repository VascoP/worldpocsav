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

	winField = newwin(3, 20, 3, 1);
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
			mvprintw(1, 1, "Register (min 3 characters)\n");
			mvprintw(7, 1, "ESC to cancel");
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
			mvprintw(1, 1, "Confirmation must match\n");
			mvprintw(7, 1, "ESC to cancel");
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
		mvprintw(1, 1, "Login\n");
		mvprintw(7, 1, "ESC to cancel");
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


