#include "main_header.h"

int syncPlayer(player * hero, WINDOW * win)
{
	int status, i, lenght;
	/*string to hold full url*/
	char * sendString;
	/*site domain*/
	char * domain = "http://www.vascop.co.cc/";
	/*full site (domain+page)*/
	char * website = (char *) malloc((strlen(domain)+strlen(hero->name)+15)*sizeof(char));

	char * stream = "sync_reply.data";

	sprintf(website, "%s/sync/%s.php", domain, hero->name);

	for(i = 0; i < 7; i++)
		lenght += (strlen(hero->spelledskills[i]) + strlen(hero->name) + 6);

	sendString = (char *) malloc(lenght*sizeof(char));

	sprintf(sendString, "name=%s&%s=%d&%s=%d&%s=%d&%s=%d&%s=%d&%s=%d&%s=%d", hero->name, hero->spelledskills[0], hero->skills[0], hero->spelledskills[1], hero->skills[1], hero->spelledskills[2], hero->skills[2], hero->spelledskills[3], hero->skills[3], hero->spelledskills[4], hero->skills[4], hero->spelledskills[5], hero->skills[5], hero->spelledskills[6], hero->skills[6]);

	showDialog(win, "Connecting to server...");

	/*POST*/
	if((status = postData(sendString, website, stream)) == 0)	
		showDialog(win, "Connected");

	else
		showDialog(win, "Couldn't connect!");

	free(sendString);
	free(website);

	return status;
}

