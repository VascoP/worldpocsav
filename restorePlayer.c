#include "main_header.h"

void restorePlayer(memoryStruct * incoming, player * hero)
{
	sscanf(incoming->memory, "%d %d %d %d %d %d", &(hero->skills[1]), &(hero->skills[2]), &(hero->skills[3]), &(hero->skills[4]), &(hero->skills[5]), &(hero->skills[6]));
}
