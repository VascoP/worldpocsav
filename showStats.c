#include "main_header.h"

/*
*	Prints a box with the player name and stats
*/
void showStats(player * hero)
{
	int i, x = 1, y = 1;
	WINDOW * winStats;
	
	mvprintw(1, 63, "Statistics");

	winStats = newwin(10, 20, 2, 59);
	
	mvwprintw(winStats, y, x, "Name:");
	mvwprintw(winStats, y++, 18-strlen(hero->name), "%s", hero->name);

	for(i = 0; i < 7; i++)
	{
		mvwprintw(winStats, y, x, "%s:", hero->spelledskills[i]);
		mvwprintw(winStats, y++, posNumb(hero->skills[i]), "%d", hero->skills[i]);
	}
	
	box(winStats, 0, 0);
	wrefresh(winStats);	

	delwin(winStats);

	return;
}

