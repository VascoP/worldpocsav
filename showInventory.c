#include "main_header.h"

void showInventory(player * hero)
{
	int x = 1, y = 1, ncols = 20;
	WINDOW * winInvent;
	item * aux = hero->inventory;
	
	mvprintw(1, 42, "Inventory");

	winInvent = newwin(10, ncols, 2, 39);
	
	if(aux == NULL)
		mvwprintw(winInvent, y, x, "Empty");
	else
	{
		while(aux != NULL)
		{
			mvwprintw(winInvent, y, x, "%d. %s", y, aux->itemName);
			mvwprintw(winInvent, y, ncols-5, "x%02d", aux->itemQuantity);
			y++;
			aux = aux->next;
		}
	}
	
	box(winInvent, 0, 0);
	wrefresh(winInvent);	

	delwin(winInvent);

	return;
}

