#include "main_header.h"

item * insertItem(item * inventory, char * itemName)
{
	item * new, * found;
	
	found = searchItem(inventory, itemName);

	if(found == NULL)
	{
		new = (item *) malloc(sizeof(item));
		new->itemName = (char *) malloc((strlen(itemName)+1)*sizeof(char));
		strcpy(new->itemName, itemName);
		new->itemQuantity = 1;
		new->next = inventory;
		return new;
	}
	else
	{
		if(found->itemQuantity < 99)
			found->itemQuantity = found->itemQuantity + 1;
	}

	return inventory;
}


