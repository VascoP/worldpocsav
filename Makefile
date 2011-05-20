DEPS= main_header.h player.h 
OBJ= game.o initScreen.o initGame.o createMenu.o continueGame.o initPlayer.o newGame.o inputField.o readString.o help.o showStats.o sendRemoteString.o gameLoop.o showInventory.o restoreLife.o showDialog.o readServer.o postData.o restorePlayer.o findItem.o exploreRegion.o initMemStruct.o uploadStats.o insertItem.o initInventory.o searchItem.o
CFLAGS= -Wall -Wextra -ansi -pedantic
LIBS= -lform -lmenu -lncurses -lm -lcurl
CC= gcc

game: $(OBJ)
	$(CC) $(CFLAGS) -o $@ $(OBJ) $(LIBS)
	rm -f *.o

%.o : %.c
	$(CC) $(CFLAGS) -c $< 
