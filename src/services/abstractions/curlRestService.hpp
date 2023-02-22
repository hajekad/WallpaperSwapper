#pragma once

#include <curl/curl.h>
#include <string>

#include "../../interface/exceptions/NetworkException.cpp"

class CurlRestService
{
    CURL * curl;
    CURLcode res;
    std::string hdUrl;

    size_t writeCallback(void * ptr, size_t size, size_t nmemb, void * userdata);

public:
    CurlRestService();
    
    void getNewWallpaperUrl();
};
