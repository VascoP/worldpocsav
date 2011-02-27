#include "main_header.h"

/*
*	Gets a name and password and loads the player stats
*/
void continueGame(void)
{
	char pass[11], name[11];
	
	/*login player and password*/
	if(inputField("Name", name, 0) == -1)
		return;
	if(inputField("Password", pass, 1) == -1)
		return;	

	/*check player in the server*/
	loadGameRemote(name, pass);
	return;
}

/*
*	Checks player's presence in the server and retrieves stats
*/
void loadGameRemote(char * name, char * password)
{
	/*retrieve player info*/
	if(sendRemotePlayer(name, password, "playerinfo.php", "load.data") == 0)
	{
		if(responseCheck("load.data", "Ok") == 0)
		{
			printw("Loaded player successfully\n");
			getch();
		}
		if(responseCheck("load.data", "WrongPass") == 0)
		{
			printw("Wrong password!\n");
			getch();
		}
		if(responseCheck("load.data", "NotFound") == 0)
		{
			printw("Player doesn't exist!\n");
			getch();
		}
	}
}
