#include "main_header.h"

/*
*	Fills a player structure with a new name/pass combo
*	Starts skills at 0, life at 100 - initializes spelled skills (makes printing easier)
*	---> EDIT: ADD CUSTOM VALUES FOR STATS / LIFE AT INITIALIZATION <---
*/
void initPlayer(char * name, char * password, player * hero)
{
	int i;

	for(i = 0; i < 7; i++)
		hero->skills[i] = 0;
	hero->spelledskills[0] = "Gold";
	hero->spelledskills[1] = "HP";
	hero->spelledskills[2] = "Speed";
	hero->spelledskills[3] = "Wisdom";
	hero->spelledskills[4] = "Agility";
	hero->spelledskills[5] = "Strenght";
	hero->spelledskills[6] = "Resistance";

	hero->name = name;
	hero->password = password;	
	hero->skills[HP] = 83;
	hero->freePoints = 0;
}
