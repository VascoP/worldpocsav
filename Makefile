DEPS= main_header.h player.h
OBJ= game.o initScreen.o initGame.o createMenu.o continueGame.o initPlayer.o newGame.o inputField.o help.o showStats.o sendRemotePlayer.o responseCheck.o gameLoop.o showInventory.o restoreLife.o showDialog.o
CFLAGS= -Wall -Wextra -ansi -pedantic
LIBS= -lform -lmenu -lncurses -lm -lcurl
CC= gcc

game: $(OBJ)
	$(CC) $(CFLAGS) -o $@ $(OBJ) $(LIBS)
	rm -f *.o

.c.o:
	$(CC) $(CFLAGS) -c $< 
