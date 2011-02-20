#include "main_header.h"

char * createForm(char *title, int y, int x)
{
	int ch, row, col;
	char *name = NULL, *out = NULL;
	FORM *form;
	FIELD *field[2];
	WINDOW *formWin;

	clear();
	/*prints title*/
	printw("%s", title);
	refresh();
		
	field[0] = new_field(1, 10, 0, 0, 0, 0);
	set_field_buffer(field[0], 0, "");
	field[1] = NULL;
	set_field_back(field[0], A_UNDERLINE);
	form = new_form(field);

	/*create form's window*/
	scale_form(form, &row, &col);
	formWin = newwin(row, col, y, x);
	keypad(formWin, TRUE);

	/* Set main window and sub window */
	set_form_win(form, formWin);
	set_form_sub(form, formWin);

	post_form(form);
	wrefresh(formWin);

	while((ch = wgetch(formWin)) != ENTER_KEY)
	{
		switch(ch)
		{
			case ' ' : break;
			case KEY_LEFT : form_driver(form, REQ_PREV_CHAR); break;
			case KEY_RIGHT : form_driver(form, REQ_NEXT_CHAR); break;
			case KEY_BACKSPACE : form_driver(form, REQ_DEL_PREV); break;
			case KEY_DC : form_driver(form, REQ_DEL_CHAR); break;
			default : form_driver(form, ch);
		}				
	}
	name = field_buffer(field[0], 0);
	clear();
	printw("%s - %d", out, strlen(field_buffer(field[0], 0)));
	getch();
	unpost_form(form);
	free_form(form);
	free_field(field[0]);

	return out;
}


