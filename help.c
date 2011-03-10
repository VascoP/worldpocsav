#include "main_header.h"

/*
*	Prints simple help screen, does nothing
*/
void help()
{
	char * string = "To be typed\n";

	clear();
	refresh();	
	printw("Help\n\n");
	printw("%s", string);	
	getch();
	clear();
	refresh();

	return;
}


