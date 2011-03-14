#include "main_header.h"

/*
*	Opens a file and checks the first line against a string
*/
int responseCheck(char * registerFile, char * string)
{
	char line[1024];
	FILE * fp = fopen(registerFile, "r");

	if(fp != NULL)
	{
		if(fgets(line, 1024, fp))
		{
			fclose(fp);
			return strcmp(string, line);
		}	
	}
	return -1;
}
