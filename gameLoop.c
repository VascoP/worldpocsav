#include "main_header.h"

/*
*	Main Ingame loop, player actions are made and syncronized with the server each turn
*/
void gameLoop(player * hero)
{
	WINDOW * winDialog = newwin(7, 78, 17, 1);
	char * choices[] = { "Explore the cave", "Go to the village", "Go to sleep", "Exit" };
	int option;

	clear();
	refresh();

	showDialog(winDialog, "");
	
	while(1)
	{
		showStats(hero);
		showInventory(hero);

		mvprintw(1, 2, "Choose your move");
		/*create menu*/
		option = createMenu(choices, arrSize(choices), 2, 1, 0);
		
		/*choice triggered functions*/
		switch(option)
		{
			/**/
			case 0:	hero = exploreRegion(winDialog, hero);
					break;
			/**/
			case 1: 
					break;
			/**/
			case 2: restoreLife(winDialog, hero, 10);
					break;
			/**/
			case 3: clear();
					refresh();
					return;
					break;
		}

		uploadStats(hero);
	}

	return;
}
