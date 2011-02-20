#ifndef _main_header_
#define _main_header_

#include <stdlib.h>
#include <string.h>
#include <ncurses.h>
#include <menu.h>
#include <form.h>
#include <dirent.h>
#include <math.h>
#include <curl/curl.h>
#include "player.h"

/*
*	---> EDIT: Please organize ._.' <---
*/

#define MARGIN 2
#define ENTER_KEY 13
#define arrSize(a) sizeof(a)/sizeof(a[0])

int screenx, screeny;

void inputField(char * label, char * string, int password);
int postData(char * data, char * url, char * stream);
void emptyRead(void *ptr, size_t size, size_t nmemb, void *stream);
int responseCheck(char * registerFile, char * string);

void showStats(player hero);
void continueGame(void);
void loadGameRemote(char * name, char * password);
void initScreen(void);
void initGame(void);
void initPlayer(char * name, char * password, player * hero);
int createMenu(char * title, char ** choices, int n_choices, int x, int y, int goback);
void newGame(void);
void help(void);
int sendRemotePlayer(char * name, char * password, char * page, char * stream);

#endif
