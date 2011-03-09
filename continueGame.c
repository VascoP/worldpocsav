#include "main_header.h"

/*
*	Gets a name and password and loads the player stats
*/
void continueGame(player * hero)
{
	char pass[11], name[11];
	
	/*login player and password*/
	if(inputField("Name", name, 0) == -1)
		return;
	if(inputField("Password", pass, 1) == -1)
		return;	

	/*check player in the server*/
	if(loadGameRemote(name, pass) == SUCCESS_LOAD)
	{
		initPlayer(name, pass, hero);
		gameLoop(hero);
	}

	return;
}

/*
*	Checks player's presence in the server and retrieves stats
*/
int loadGameRemote(char * name, char * password)
{
	/*retrieve player info*/
	if(sendRemotePlayer(name, password, "playerinfo.php", "load.data") == 0)
	{
		if(responseCheck("load.data", "Ok") == 0)
			return SUCCESS_LOAD;				

		if(responseCheck("load.data", "WrongPass") == 0)
			return WRONG_PASS;			

		if(responseCheck("load.data", "NotFound") == 0)
			return NOT_FOUND;
	}
	return COULDNT_POST;
}

