#include "main_header.h"

player * exploreRegion(WINDOW * win, player * hero)
{
	hero->inventory = findItem(win, hero->inventory);
	return hero;
}


