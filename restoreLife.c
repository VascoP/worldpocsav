#include "main_header.h"

void restoreLife(WINDOW * win, player * hero, int amount)
{
	int health = hero->skills[HP], gain;
	char * gainstring = "You go to sleep and when you wake up you feel much better.";
	char * fullstring = "You're full of energy and unable to fall asleep.";
	char * out = (char *) malloc((strlen(gainstring)+12)*sizeof(char));

	if(health + amount >= 100)
		health = 100;
	else
		health += amount;

	gain = health - hero->skills[HP];

	hero->skills[HP] = health;

	sprintf(out, "%s (+%d HP)", gainstring, gain);
	
	if(gain > 0)	
		showDialog(win, out);
	else
		showDialog(win, fullstring);
	
	return;
}
