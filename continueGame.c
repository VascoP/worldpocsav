#include "main_header.h"

/*
*	Gets a name and password and loads the player stats
*/
void continueGame(void)
{
	char pass[11], name[11];
	
	/*login player and password*/
	inputField("Choose name", name, 0);
	inputField("Choose password", pass, 1);	

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
	sendRemotePlayer(name, password, "playerinfo.php", "load.data");
	
	/*get player info - inicially just confirm it exists*/

}
