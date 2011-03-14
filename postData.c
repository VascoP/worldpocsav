#include "main_header.h"

/*
*	Opens a connection to an url
*	POST's data to url, saves response to file and closes connection
*/
int postData(char * outgoing, char * url, memoryStruct * incoming)
{
	CURL *curl;
	CURLcode res;

	curl = curl_easy_init();
	if(curl) 
	{
		curl_easy_setopt(curl, CURLOPT_URL, url);
		curl_easy_setopt(curl, CURLOPT_POSTFIELDS, outgoing);
		curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, readServer);
  		curl_easy_setopt(curl, CURLOPT_WRITEDATA, (void *)incoming);
		res = curl_easy_perform(curl);
		curl_easy_cleanup(curl);
	}
	else
	{
		printw("Can't start easy curl handle\n");
		getch();
	}	

	return res;
}
