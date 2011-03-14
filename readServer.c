#include "main_header.h"

size_t readServer(void *ptr, size_t size, size_t nmemb, void *data)
{
	size_t realsize = size * nmemb;
	memoryStruct *mem = (memoryStruct *)data;

	mem->memory = realloc(mem->memory, mem->size + realsize + 1);

	if (mem->memory == NULL) 
	{
		/* out of memory! */ 
		exit(EXIT_FAILURE);
	}

	memcpy(&(mem->memory[mem->size]), ptr, realsize);
	mem->size += realsize;
	mem->memory[mem->size] = 0;

	return realsize;
}
