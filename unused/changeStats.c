#include "main_header.h"

void changeStats(player * hero, WINDOW * winsStats)
{
	int i, x = 1, y = 1;
	
	mvprintw(1, 42, "Update Stats");
	
	mvwprintw(winsStats, y, x, "Free points:");
	mvwprintw(winsStats, y, posNumb(hero->freePoints), "%d", hero->freePoints);
	y += 2;

	for(i = 1; i < 7; i++)
	{
		mvwprintw(winsStats, y, x, "%s:", hero->spelledskills[i]);
		mvwprintw(winsStats, y++, posNumb(hero->skills[i]), "%d", hero->skills[i]);
	}
	
	box(winsStats, 0, 0);
	wrefresh(winsStats);	

	return;

}
