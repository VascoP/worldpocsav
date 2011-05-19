#include "main_header.h"

memoryStruct initMemStruct(void)
{
	memoryStruct incoming;

	incoming.memory = malloc(1);
	incoming.size = 0;

	return incoming;
}
