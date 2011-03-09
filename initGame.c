#include "main_header.h"

/*
*	Initializes the main menu with options to create a player and play a new game
*	or continue with a previously created character
*/
void initGame()
{
	/*items in the menu*/
	char *choices[] = { "New Game", "Continue Game", "Help", "Exit" };
	int option;
	player * hero = (player *) malloc(sizeof(player));

	while(1)
	{
		/*create menu*/
		option = createMenu("--- World of Pocsav ---", choices, arrSize(choices), MARGIN, 0, 0);

		/*choice triggered functions*/
		switch(option)
		{
			/*new game*/
			case 0:	newGame(hero);
					break;
			/*continue game*/
			case 1: continueGame(hero);
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



