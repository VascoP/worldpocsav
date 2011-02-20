#include "main_header.h"

void sendRemotePlayer(char * name, char * password, char * page)
{
	char * sendString = (char *) malloc((strlen("name=&pass=")+strlen(hero.name)+strlen(hero.password)+1)*sizeof(char));
	char * domain = "http://www.vascop.co.cc/";
	char * website = (char *) malloc((strlen(domain)+strlen(page)+1)*sizeof(char));

	sprintf(website, "%s%s", domain, website);

	sprintf(sendString, "name=%s&pass=%s", hero.name, hero.password);

	if(postData(sendString, website) == 0)
	{
		clear();
		printw("User %s with password %s successfuly created", hero.name, hero.password);
		refresh();
		getch();
		clear();
		refresh();
	}
	free(sendString);
}

int postData(char * data, char * url)
{
	CURL *curl;
	CURLcode res;
	FILE * stream = fopen("register.data", "a");

	curl = curl_easy_init();
	if(curl) 
	{
		curl_easy_setopt(curl, CURLOPT_URL, url);
		curl_easy_setopt(curl, CURLOPT_POSTFIELDS, data);
		curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, NULL);
	    curl_easy_setopt(curl, CURLOPT_WRITEDATA, stream);
		res = curl_easy_perform(curl);
		curl_easy_cleanup(curl);
		fclose(stream);
	}
	return res;
}

