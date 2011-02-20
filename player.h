#ifndef _player_
#define _player_

#define Gold 0
#define Life 1
#define Speed 2
#define Wisdom 3
#define Agility 4
#define Strenght 5
#define Resistance 6

typedef struct player
{
	char *name;
	char *password;
	int skills[7];
    char *spelledskills[7];

} player;


#endif
