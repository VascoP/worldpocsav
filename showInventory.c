#include "main_header.h"

void showInventory(player * hero)
{
	int x = 1, y = 1;
	WINDOW * winInvent;
	
	mvprintw(1, 42, "Inventory");

	winInvent = newwin(10, 20, 2, 39);
	
	if(hero->inventory == NULL)
		mvwprintw(winInvent, y, x, "Empty");
	else
		mvwprintw(winInvent, y, x, "%d. %s", hero->inventory->itemPosition, hero->inventory->itemName);		
	
	box(winInvent, 0, 0);
	wrefresh(winInvent);	

	delwin(winInvent);

	return;
}

