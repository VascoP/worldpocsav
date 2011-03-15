#include "main_header.h"

/*
*	Gets a name and password and loads the player stats
*/
void continueGame(player * hero)
{
	char * outgoing;
	char pass[11], name[11];
	memoryStruct incoming;
	
	/*login player and password*/
	if(inputField("Name", name, 0, 0) == -1)
		return;
	if(inputField("Pass", pass, 1, 0) == -1)
		return;	

	outgoing = (char *)malloc((strlen(name)+strlen(pass)+strlen("name=&pass=")+1)*sizeof(char));
	incoming.memory = malloc(1);
	incoming.size = 0;

	sprintf(outgoing, "name=%s&pass=%s", name, pass);

	printw("Connecting...");
	refresh();

	if(sendRemoteString(outgoing, "playerinfo.php", &incoming) == 0)
	{
		if(strcmp(incoming.memory, "WrongPass") == 0)
		{
			printw("Wrong password!\n");
			refresh();
			getch();
			clear();
			refresh();
		}
		else 
		{ 
			if(strcmp(incoming.memory, "NotFound") == 0)
			{
				printw("Player not found!\n");
				refresh();
				getch();
				clear();
				refresh();
			}	
			else
			{
				initPlayer(name, pass, hero);
				restorePlayer(&incoming, hero);
				gameLoop(hero);	
			}
		}
	}

	if(incoming.memory)
    	free(incoming.memory);

	return;
}

