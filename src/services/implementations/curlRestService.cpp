#include "../abstractions/curlRestService.hpp"

CurlRestService::CurlRestService() {
    curl = curl_easy_init();
    curl_global_init(CURL_GLOBAL_ALL);
    hdUrl = "";
}

size_t dataSize = 0;

size_t curlWriteFunction(void * ptr, size_t size, size_t nmemb, void * userdata) {
    char ** stringToWrite = (char **) userdata;
    const char * input = (const char *) ptr;

    if (nmemb == 0) {
        return 0;
    }
    if(! * stringToWrite) {
        * stringToWrite = (char *) malloc(nmemb + 1);
    } else {
        * stringToWrite = (char *) realloc(* stringToWrite, dataSize + nmemb + 1);
    }

    memcpy(* stringToWrite + dataSize, input, nmemb);
    
    dataSize += nmemb;
    (* stringToWrite) [dataSize] = '\0';
    
    return nmemb;
}

void CurlRestService::getNewWallpaperUrl() {
    if(!curl) {
        throw NetworkException("Could not instantiate curl service.");
    }
    
    char * data = NULL;

    curl_easy_setopt(curl, CURLOPT_URL, KEY_URL);
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, &curlWriteFunction);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &data);

    CURLcode res = curl_easy_perform(curl);

    if(res != CURLE_OK) {
        throw NetworkException(curl_easy_strerror(res));
    }

    curl_easy_cleanup(curl);

    hdUrl = data;

    clearHdUrl();
}

void CurlRestService::getNewWallpaperImage() {
    dataSize = 0;

    FILE * targetFile = fopen("assets/current.jpg", "w");
    CURL * curl = curl_easy_init();

    curl_global_init(CURL_GLOBAL_ALL);

    if(!curl) {
        throw NetworkException("Could not instantiate curl service.");
    }
    char * data = NULL;

    curl_easy_setopt(curl, CURLOPT_URL, hdUrl.c_str());
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &data);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, targetFile);

    CURLcode res = curl_easy_perform(curl);

    if(res != CURLE_OK) {
        throw NetworkException(curl_easy_strerror(res));
    }
}

void CurlRestService::clearHdUrl() {
    std::string templ = "\"" + URL_TYPE + "\":\"";
    size_t i = 0;
    size_t j = 0;
    
    for(; i < hdUrl.size(); i++) {
        if(hdUrl[i] == templ[j]) {
            j++;
            if(j == templ.size()) {
                break;
            }
        } else {
            j = 0;
        }
    }

    if(i == hdUrl.size()) {
        throw NetworkException("url is missing in the response json.");
    }

    i++;

    std::string tmp = "";

    while(hdUrl[i] != '"') {
        tmp += hdUrl[i];
        i++;
    }

    hdUrl = tmp;
}
