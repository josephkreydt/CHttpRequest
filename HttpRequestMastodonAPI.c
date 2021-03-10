#include <stdio.h>
#include <curl/curl.h>
/* install libcurl in Ubuntu with "sudo apt install libcurl libcurl4-openssl-dev" */
/* compile with "gcc -o mastodon mastodon.c -lcurl"*/
/* run the compiled program with "./mastodon"*/
 
int main(void)
{
  CURL *curl;
  CURLcode response;
  /* In windows, this will init the winsock stuff */ 
  curl_global_init(CURL_GLOBAL_ALL);
 
  /* get a curl handle */ 
  curl = curl_easy_init();
  if(curl) {
    /* initialize struct that will hold auth token for request header */
    struct curl_slist *chunk = NULL;
    /* add auth token to request header */
    chunk = curl_slist_append(chunk, "Authorization: Bearer -tQ5LU7LRjaQMPJYpQw9VQVKOy18Iz0QOD_tafKogl4");
    /* set request header */
    curl_easy_setopt(curl, CURLOPT_HTTPHEADER, chunk);
    /* set URL for POST */ 
    curl_easy_setopt(curl, CURLOPT_URL, "https://mstdn.social/api/v1/statuses");
    /* set form parameters. to add more, use this pattern:
        "status=Mastodon API request from C!&visibility=public&sheduled_at=2021-02-14" */
    curl_easy_setopt(curl, CURLOPT_POSTFIELDS, "status=Mastodon API request from C!");
 
    /* Post the HTTP request, and store response in "response" variable */ 
    response = curl_easy_perform(curl);
    /* Check for errors */ 
    if(response != CURLE_OK)
      fprintf(stderr, "curl_easy_perform() failed: %s\n",
              curl_easy_strerror(response));
 
    /* cleanup */ 
    curl_easy_cleanup(curl);
  }
  curl_global_cleanup();
  return 0;
}

/* Joseph Kreydt */
