#include "main_header.h"

void gameLoop(player * hero)
{
	WINDOW * winDialog = newwin(7, 78, 17, 1);
	char * choices[] = { "Explore the cave", "Go to the village", "Go to sleep", "Exit" };
	char * page;
	int option;
	char * outgoing;
	memoryStruct incoming;
	incoming.size = 0;

	outgoing = (char *) malloc((strlen("name=&Gold=%d&HP=%d&Speed=%d&Wisdom=%d&Agility=%d&Strenght=%d&Resistance=%d")+strlen(hero->name)+1)*sizeof(char));

	page = (char *) malloc((strlen(hero->name)+strlen("sync/.php")+1)*sizeof(char));
	sprintf(page, "sync/%s.php", hero->name);

	incoming.memory = malloc(1);
	sprintf(outgoing, "name=%s&Gold=%d&HP=%d&Speed=%d&Wisdom=%d&Agility=%d&Strenght=%d&Resistance=%d", hero->name, hero->skills[0], hero->skills[1], hero->skills[2], hero->skills[3], hero->skills[4], hero->skills[5], hero->skills[6]);
	sendRemoteString(outgoing, page, &incoming);
	free(incoming.memory);

	clear();
	refresh();

	showDialog(winDialog, "");
	
	while(1)
	{
		showStats(hero);
		showInventory(hero);

		incoming.memory = malloc(1);

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
			case 1: findItem(hero);
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

		sprintf(outgoing, "name=%s&Gold=%d&HP=%d&Speed=%d&Wisdom=%d&Agility=%d&Strenght=%d&Resistance=%d", hero->name, hero->skills[0], hero->skills[1], hero->skills[2], hero->skills[3], hero->skills[4], hero->skills[5], hero->skills[6]);
		sendRemoteString(outgoing, page, &incoming);

   		free(incoming.memory);
	}

	return;
}
