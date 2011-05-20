#include "main_header.h"

item * findItem(WINDOW * win, item * inventory)
{
	int	whichItem;
	char * item = "Sword";
	char * found = "You've just found a";
	char * out;
	
	whichItem = rand() % 3 + 1;

	inventory = insertItem(inventory, item); 
	out = (char *) malloc((strlen(found)+strlen(item)+3)*sizeof(char)); 
	sprintf(out, "%s %s!", found, item);

	showDialog(win, out);

	free(out);

	return inventory;
}


