#include "main_header.h"

/*
*	Initializes the main menu with options to create a player and play a new game
*	or continue with a previously created character
*/
void initGame()
{
	/*items in the menu*/
	char * choices[] = { "Continue Game", "New Game", "Help", "Exit" };
	int option;
	player * hero = (player *) malloc(sizeof(player));

	while(1)
	{
		mvprintw(1, 1, "World of Pocsav");
		/*create menu*/
		option = createMenu(choices, arrSize(choices), 2, 1, 0);

		/*choice triggered functions*/
		switch(option)
		{
			/*continue game*/
			case 0:	continueGame(hero);
					break;
			/*new game*/
			case 1: newGame(hero);
					break;
			/*help screen*/
			case 2: help();
					break;
			/*exit*/
			case 3: return;
					break;
		}
	}
	free(hero);
}



