#include "main_header.h"

/*
*	Presents a field with a label, writes the input into string
*	Option: password - asks for confirmation and displays *'s instead (*'s not implemented yet)
*	---> EDIT: UPDATE IN ORDER TO RECEIVE MIN/MAX INPUT VALUES <---
*/
void inputField(char * label, char * string, int password)
{
	char check[11];

	clear();
	refresh();

	curs_set(1);
	echo();
	refresh();

	if(password)
	{
		/*password input loops until passwords match and complies with limits*/
		do
		{
			printw("[3-10] letters long\n");
			printw("%s: \n", label);
			getnstr(string, 10);
			strcpy(check, string);
			printw("Confirmation must match\n");
			printw("Confirm: \n");
			string[0] = '\0';
			getnstr(string, 10);
			clear();
			refresh();
		}
		while((strcmp(check, string) != 0) || strlen(string) < 3);
	}
	else
	{
		/*input loops until it complies with limits*/
		do
		{
			printw("[3-10] letters long\n");
			printw("%s: \n", label);
			getnstr(string, 10);		
			clear();
			refresh();
		}
		while(strlen(string) < 3);
	}	

	noecho();
	curs_set(0);	
	clear();
	refresh();
	return;
}


