#include "main_header.h"

/*
*	Creates a Menu Widget (ncurses) from a list of items (requires size) on line y, column x
*	Option: go back (if 1) presents an option to exit the menus
* 	Returns id of the selected option
*/
int createMenu(char * title, char **choices, int n_choices, int y, int x, int goback)
{
	char *back = "Go back";
	int i, c, test = 0, width = strlen(back)+1;
	MENU *menu;
	ITEM **menuItems;
	WINDOW *menuWin;

	clear();
	/*prints title*/
	printw("%s", title);
	refresh();

	/*initializes items*/
	menuItems = (ITEM **)malloc((n_choices+goback+1)*sizeof(ITEM *));

	for(i = 0; i < n_choices; i++)
	{
		/*finds menu width*/
		if((test = strlen(choices[i])+1) > width)
			width = test;
		menuItems[i] = new_item(choices[i], NULL);
	}
	/*adds go back button*/
	if(goback == 1)
		menuItems[i++] = new_item(back, NULL);
	menuItems[n_choices+goback] = (ITEM *)NULL;

	/*Creates the menu from the list of items*/
	menu = new_menu((ITEM**)menuItems);

	/*create menu's window*/
	menuWin = newwin(n_choices+goback, width, y, x);
	keypad(menuWin, TRUE);

	/* Set menu's main window*/
	set_menu_win(menu, menuWin);

	/*draw menu*/
	post_menu(menu); 
	wrefresh(menuWin);

	/*gets the position on the menu until selection*/
	while((c = wgetch(menuWin)) != ENTER_KEY) 
	{
		switch(c)
		{
			case KEY_DOWN:	menu_driver(menu, REQ_DOWN_ITEM);
							break;
			case KEY_UP:	menu_driver(menu, REQ_UP_ITEM);
							break;
		}
	}
	/*get the selected index*/
	c = item_index(current_item(menu));

	/*gets rid of shit*/
	unpost_menu(menu);
	free_menu(menu);
	for(i = 0; i < n_choices+goback+1; i++)
		free_item(menuItems[i]);
	free(menuItems);
	delwin(menuWin);
	clear();

	/*returns the index of the choice made*/
	return c;
}

