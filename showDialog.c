#include "main_header.h"

void showDialog(WINDOW * winDialog, char * string)
{	
	wclear(winDialog);	
	mvwprintw(winDialog, 1, 1, "Dialog: ");	
	wprintw(winDialog, "%s", string);
	box(winDialog, 0, 0);
	wrefresh(winDialog);
	refresh();

	return;

}

