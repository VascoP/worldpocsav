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

#define ENTER_KEY 13
#define ESCAPE_KEY 27

#define arrSize(a) sizeof(a)/sizeof(a[0])
#define posNumb(a) a > 0 ? 17-((int)log10(a)) : 17

#define SUCCESS_REGISTER 0
#define SUCCESS_LOAD 1
#define WRONG_PASS -1
#define NOT_FOUND -2
#define COULDNT_POST -3

int screenx, screeny;

typedef struct memoryStruct {
  char * memory;
  size_t size;
} memoryStruct;

int inputField(char * label, char * string, int password, int confirm);
int postData(char * outgoing, char * url, memoryStruct * incoming);
size_t readServer(void *ptr, size_t size, size_t nmemb, void *stream);
int responseCheck(char * registerFile, char * string);
char * readString(char * string, int password, WINDOW * win);

void showDialog(WINDOW * winDialog, char * string);
void showInventory(player * hero);
void showStats(player * hero);
void continueGame(player * hero);
int loadGameRemote(char * name, char * pass);
void initScreen(void);
void initGame(void);
void initPlayer(char * name, char * pass, player * hero);
void restorePlayer(memoryStruct * incoming, player * hero);
int createMenu(char ** choices, int n_choices, int x, int y, int goback);
void newGame(player * hero);
void help(void);
int sendRemoteString(char * sendString, char * page, memoryStruct * incoming);
int syncPlayer(player * hero, WINDOW * win, memoryStruct * incoming);
void gameLoop(player * hero);

int findItem(player * hero);

#endif
