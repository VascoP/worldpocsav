#include "main_header.h"

/*
*	Asks for a new player's name and password, initializes its stats
*	and sends the information to the server
*/
void newGame(player * hero)
{
	char * outgoing;
	char pass[11], name[11];
	memoryStruct incoming;

	/*simple form like input for name and password*/
	if(inputField("Name", name, 0, 1) == -1)
		return;
	if(inputField("Pass", pass, 1, 1) == -1)
		return;

	/*starts structure with the name/pass and initial stats*/
	initPlayer(name, pass, hero);

	outgoing = (char *)malloc((strlen(name)+strlen(pass)+strlen("name=&pass=")+1)*sizeof(char));
	incoming.memory = malloc(1);
	incoming.size = 0;

	sprintf(outgoing, "name=%s&pass=%s", name, pass);

	printw("Connecting...");
	refresh();

	/*register new player*/
	if(sendRemoteString(outgoing, "register.php", &incoming) == SUCCESS_REGISTER)
	{
		if(strcmp(incoming.memory, "dup") == 0)
		{
			printw("Username already exists!\n");
			getch();
			clear();
			refresh();
		}
		else
		{
			if(strcmp(incoming.memory, "ok") == 0)
			{
				gameLoop(hero);
			}
			else
			{
				printw("Problem connecting to server!\n");
				getch();
				clear();
				refresh();
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
	free(outgoing);

	return;
}
