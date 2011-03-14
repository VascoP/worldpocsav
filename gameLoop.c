#include "main_header.h"

void gameLoop(player * hero)
{
	WINDOW * winDialog = newwin(7, 78, 17, 1);
	char *choices[] = { "Explore the cave", "Go to the village", "Go to sleep", "Exit" };
	int option;

	memoryStruct incoming;
	incoming.memory = malloc(1);
	incoming.size = 0;

	clear();
	refresh();

	
	while(1)
	{
		showStats(hero);
		showInventory(hero);
		syncPlayer(hero, winDialog, &incoming);

		mvprintw(1, 2, "Choose your move");
		/*create menu*/
		option = createMenu(choices, arrSize(choices), 2, 1, 0);
		
		/*choice triggered functions*/
		switch(option)
		{
			/**/
			case 0:	
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
	}

	if(incoming.memory)
    	free(incoming.memory);

	return;
}
