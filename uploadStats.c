#include "main_header.h"

/*
*	Sends current player stats to the server
*/
void uploadStats(player * hero)
{
	char * outgoing, * page;
	memoryStruct incoming;

	page = (char *) malloc((strlen(hero->name)+strlen("sync/.php")+1)*sizeof(char));
	sprintf(page, "sync/%s.php", hero->name);

	outgoing = (char *) malloc((strlen("name=&Gold=100&HP=100&Speed=100&Wisdom=100&Agility=100&Strenght=100&Resistance=100")+strlen(hero->name)+1)*sizeof(char));

	sprintf(outgoing, "name=%s&Gold=%d&HP=%d&Speed=%d&Wisdom=%d&Agility=%d&Strenght=%d&Resistance=%d", hero->name, hero->skills[0], hero->skills[1], hero->skills[2], hero->skills[3], hero->skills[4], hero->skills[5], hero->skills[6]);

	incoming = initMemStruct();
	sendRemoteString(outgoing, page, &incoming);
	free(incoming.memory);

}


