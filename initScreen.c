#include "main_header.h"

/*
*	Initializes miscelaneous settings for the console
*	---> EDIT: Check for console basic capabilities (ie color) before using <---
*/
void initScreen()
{
	/*starts ncurses*/
	initscr();
	/*gets terminal size*/
	getmaxyx(stdscr,screeny,screenx);
	/*gets input before ENTER is pressed*/
 	cbreak();
	/*ENTER doesnt insert a newline*/
	nonl();
	/*initialize color variables and routines*/
	start_color();
	/*start full keyboard capture*/
	keypad(stdscr, TRUE);
	/*do not show pressed keys*/
	noecho();
	/*do not show cursor*/
	curs_set(0);

	return;
}



