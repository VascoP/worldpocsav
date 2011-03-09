#include "main_header.h"

/*
*	Asks for a new player's name and password, initializes its stats
*	and sends the information to the server
*/
void newGame(player * hero)
{
	char pass[11], name[11];
	
	char * registerFile = "register.data";

	/*simple form like input for name and password*/
	if(inputField("Choose name", name, 0) == -1)
		return;
	if(inputField("Choose password", pass, 1) == -1)
		return;
	/*starts structure with the name/pass and initial stats*/
	initPlayer(name, pass, hero);

	/*register new player*/
	if(sendRemotePlayer(name, pass, "register.php", registerFile) == SUCCESS_REGISTER)
	{
		if(responseCheck(registerFile, "dup") == 0)
		{
			printw("Username already exists!\n");
			getch();
		}
		else
		{
			gameLoop(hero);
		}
	}

	return;
}
