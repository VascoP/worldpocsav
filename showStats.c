#include "main_header.h"

#define posNumb(a) a > 0 ? 17-((int)log10(a)) : 17

/*
*	Prints a box with the player name and stats
*/
void showStats(player hero)
{
	int i, x = 1, y = 1;
	WINDOW * winStats;

	clear();
	
	winStats = newwin(10, 20, 1, 1);
	keypad(winStats, TRUE);
	
	mvwprintw(winStats, y, x, "Name:");
	mvwprintw(winStats, y++, 18-strlen(hero.name), "%s", hero.name);

	for(i = 0; i < 7; i++)
	{
		mvwprintw(winStats, y, x, "%s:", hero.spelledskills[i]);
		mvwprintw(winStats, y++, posNumb(hero.skills[i]), "%d", hero.skills[i]);
	}
	
	box(winStats, 0, 0);
	wrefresh(winStats);	
	wgetch(winStats);

	delwin(winStats);
}
