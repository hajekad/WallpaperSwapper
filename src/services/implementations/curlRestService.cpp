#include "../abstractions/curlRestService.hpp"

CurlRestService::CurlRestService() {
    curl = curl_easy_init();
    curl_global_init(CURL_GLOBAL_ALL);
    hdUrl = "";
    dataSize = 0;
}

size_t curlWriteFunction(void* ptr, size_t size, size_t nmemb, void* userdata) {
    char** stringToWrite=(char**)userdata;
    const char* input=(const char*)ptr;
    if(nmemb==0) return 0;
    if(!*stringToWrite)
        *stringToWrite = (char *) malloc(nmemb+1);
    else
        *stringToWrite = (char *) realloc(*stringToWrite, dataSize+nmemb+1);
    memcpy(*stringToWrite+dataSize, input, nmemb);
    dataSize+=nmemb;
    (*stringToWrite)[dataSize]='\0';
    return nmemb;
}

void CurlRestService::getNewWallpaperUrl() {
    if(!curl) {
        throw NetworkException("Could not instantiate curl service.");
    }

    char * data = NULL;

    curl_easy_setopt(curl, CURLOPT_URL, "https://api.nasa.gov/planetary/apod?api_key=3uALHm6PeNktClBFYS2DQgTi1cYM1FoYCzwI9SGa");
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &data);
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, &curlWriteFunction);

    CURLcode res = curl_easy_perform(curl);

    std::cout << std::endl << res << std::endl;

    if(res != CURLE_OK) {
        throw NetworkException(curl_easy_strerror(res));
    }

    curl_easy_cleanup(curl);

    std::cout << data << std::endl;
}
