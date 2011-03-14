#include "main_header.h"

int sendRemoteString(char * sendString, char * page, memoryStruct * incoming)
{
	int status;
	/*site domain*/
	char * domain = "http://www.vascop.co.cc/";
	/*full site (domain+page)*/
	char * website = (char *) malloc((strlen(domain)+strlen(page)+1)*sizeof(char));

	sprintf(website, "%s%s", domain, page);

	/*POST*/
	status = postData(sendString, website, incoming);
	
	free(website);

	return status;
}
