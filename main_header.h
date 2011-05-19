/* 
*	World of Pocsav - Online game with a local ascii command line interface game
*	Requires ncurses and libcurl packages, internet connection to play
*	
*	Programmed by VascoP - vascogpinho@gmail.com
*/

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

/*Keyboard keys definitions lacking in curses*/
#define ENTER_KEY 13
#define ESCAPE_KEY 27

/*Array size finding hack*/
#define arrSize(a) sizeof(a)/sizeof(a[0])

/*Positioning crap*/
#define posNumb(a) a > 0 ? 17-((int)log10(a)) : 17

/*Global terminal size*/
int screenx, screeny;

/*Server Related*/
typedef struct memoryStruct {
  char * memory;
  size_t size;
} memoryStruct;

memoryStruct initMemStruct(void);

/*Server Related*/
int postData(char * outgoing, char * url, memoryStruct * incoming);
size_t readServer(void *ptr, size_t size, size_t nmemb, void *stream);
int sendRemoteString(char * sendString, char * page, memoryStruct * incoming);
void uploadStats(player * hero);

/*Input handling*/
int inputField(char * label, char * string, int password, int confirm);
char * readString(char * string, int password, WINDOW * win);
int createMenu(char ** choices, int n_choices, int x, int y, int goback);

/*Ingame menus*/
void showDialog(WINDOW * winDialog, char * string);
void showInventory(player * hero);
void showStats(player * hero);

/*Game initialization*/
void initScreen(void);
void initGame(void);
void gameLoop(player * hero);

/*New Game / Continue Game*/
void newGame(player * hero);
void initPlayer(char * name, char * pass, player * hero);
void continueGame(player * hero);
void restorePlayer(memoryStruct * incoming, player * hero);

/*Help*/
void help(void);

/*Ingame actions*/
void restoreLife(WINDOW * win, player * hero, int amount);
void exploreRegion(player * hero);
void findItem(player * hero);

#endif
