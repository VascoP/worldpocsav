#include "main_header.h"

item * searchItem(item * inventory, char * itemName)
{
	item * aux = inventory;

	while(aux != NULL)
	{
		if(strcmp(aux->itemName, itemName) != 0)
			aux = aux->next;
		else
			return aux;
	}
	return NULL;
}


