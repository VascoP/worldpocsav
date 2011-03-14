#include "main_header.h"

/*
*	Gets a name/pass combo and a page to POST to 
*	Sends a the POST information to the domain/page url
*/
int sendRemotePlayer(char * name, char * password, char * page, char * stream)
{
	int status;
	/*string to hold full url*/
	char * sendString = (char *) malloc((strlen("name=&pass=")+strlen(name)+strlen(password)+1)*sizeof(char));
	/*site domain*/
	char * domain = "http://www.vascop.co.cc/";
	/*full site (domain+page)*/
	char * website = (char *) malloc((strlen(domain)+strlen(page)+1)*sizeof(char));

	sprintf(website, "%s%s", domain, page);

	sprintf(sendString, "name=%s&pass=%s", name, password);

	clear();
	printw("Connecting to server...\n");
	refresh();

	/*POST*/
	if((status = postData(sendString, website, stream)) == 0)
	{	
		clear();
		refresh();
	}
	else
	{
		printw("Couldn't connect!\n");
		getch();
		clear();
		refresh();
	}
	free(sendString);
	free(website);

	return status;
}

/*
*	Opens a connection to an url
*	POST's data to url, saves response to file and closes connection
*/
int postData(char * data, char * url, char * stream)
{
	CURL *curl;
	CURLcode res;
	FILE * file = fopen(stream, "w");

	curl = curl_easy_init();
	if(curl) 
	{
		curl_easy_setopt(curl, CURLOPT_URL, url);
		curl_easy_setopt(curl, CURLOPT_POSTFIELDS, data);
		curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, readServer);
	    curl_easy_setopt(curl, CURLOPT_WRITEDATA, file);
		res = curl_easy_perform(curl);
		curl_easy_cleanup(curl);
		fclose(file);
	}
	else
	{
		printw("Can't start easy curl handle\n");
		getch();
	}	
	return res;
}

