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

	incoming = initMemStruct();

	/*simple form like input for name and password*/
	if(inputField("Name", name, 0, 1) == -1)
		return;
	if(inputField("Pass", pass, 1, 1) == -1)
		return;

	/*prepare message to send to server*/
	outgoing = (char *)malloc((strlen(name)+strlen(pass)+strlen("name=&pass=")+1)*sizeof(char));
	sprintf(outgoing, "name=%s&pass=%s", name, pass);

	printw("Connecting...");
	refresh();

	/*send message to server page*/
	if(sendRemoteString(outgoing, "register.php", &incoming) == 0)
	{
		if(strcmp(incoming.memory, "Duplicate") == 0)
		{
			printw("Username already exists!\n");
			getch();
			clear();
			refresh();
		}
		if(strcmp(incoming.memory, "Ok") == 0)
		{
			/*starts structure with the name/pass and initial stats*/
			initPlayer(name, pass, hero);
			uploadStats(hero);
			gameLoop(hero);
		}
		else
		{
			printw("We're having server problems, couldn't register\n");
			getch();
			clear();
			refresh();
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
