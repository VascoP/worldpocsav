#include "main_header.h"

/*
*	Fills a player structure with a new name/pass combo
*	Starts skills - initializes spelled skills (makes printing easier)
*	Initializes inventory
*/
void initPlayer(char * name, char * pass, player * hero)
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
	hero->pass = pass;	
	hero->skills[HP] = 50;
	hero->freePoints = 0;

	hero->inventory = initInventory();
	hero->inventory = insertItem(hero->inventory, "Map\0");
}
