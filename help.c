#include "main_header.h"

/*
*	Prints simple help screen, does nothing
*/
void help()
{
	char * string = "To be typed\n";
	
	printw("Help\n\n");
	printw("%s", string);	
	getch();

	return;
}


