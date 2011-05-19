#include "main_header.h"

/*
*	Sends a string to a webpage within the domain and stores the reply into a memory structure
*/
int sendRemoteString(char * sendString, char * page, memoryStruct * incoming)
{
	int status;
	/*site domain*/
	char * domain = "http://localhost/pocsav/";
	/*full site (domain+page)*/
	char * website = (char *) malloc((strlen(domain)+strlen(page)+1)*sizeof(char));
	sprintf(website, "%s%s", domain, page);

	/*POST*/
	status = postData(sendString, website, incoming);
	
	free(website);

	return status;
}
