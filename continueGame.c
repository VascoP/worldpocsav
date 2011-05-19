#include "main_header.h"

/*
*	Gets a name and password and loads the player stats from the server
*/
void continueGame(player * hero)
{
	char * outgoing;
	char pass[11], name[11];
	memoryStruct incoming;

	incoming = initMemStruct();
	
	/*simple form like input for name and password*/
	if(inputField("Name", name, 0, 0) == -1)
		return;
	if(inputField("Pass", pass, 1, 0) == -1)
		return;	

	/*prepare message to send to server*/
	outgoing = (char *)malloc((strlen(name)+strlen(pass)+strlen("name=&pass=")+1)*sizeof(char));
	sprintf(outgoing, "name=%s&pass=%s", name, pass);

	printw("Connecting...");
	refresh();

	/*send message to server page*/
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
	else
	{
		printw("Problem connecting to server!\n");
		getch();
		clear();
		refresh();
	}

	if(incoming.memory)
    	free(incoming.memory);

}

