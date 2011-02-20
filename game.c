/* 
*	World of Pocsav - Online game with a local ascii command line interface game
*	Requires ncurses and libcurl packages, internet connection to play
*	
*	Programmed by VascoP - vascogpinho@gmail.com
*/
#include "main_header.h"

int main (void)
{
	/*sets screen variables and environment*/
	initScreen();
	/*main menu and game loop*/
	initGame();
	/*get rid of stdscr*/
	endwin();
  
	return EXIT_SUCCESS;
}
