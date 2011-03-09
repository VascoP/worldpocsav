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
#define ESCAPE_KEY 27
#define arrSize(a) sizeof(a)/sizeof(a[0])

#define SUCCESS_REGISTER 0
#define SUCCESS_LOAD 1
#define WRONG_PASS -1
#define NOT_FOUND -2
#define COULDNT_POST -3

int screenx, screeny;

int inputField(char * label, char * string, int password);
int postData(char * data, char * url, char * stream);
void emptyRead(void *ptr, size_t size, size_t nmemb, void *stream);
int responseCheck(char * registerFile, char * string);
char * readString(char * string, int password);

void showStats(player * hero);
void continueGame(player * hero);
int loadGameRemote(char * name, char * password);
void initScreen(void);
void initGame(void);
void initPlayer(char * name, char * password, player * hero);
int createMenu(char * title, char ** choices, int n_choices, int x, int y, int goback);
void newGame(player * hero);
void help(void);
int sendRemotePlayer(char * name, char * password, char * page, char * stream);
void gameLoop(player * hero);

#endif
