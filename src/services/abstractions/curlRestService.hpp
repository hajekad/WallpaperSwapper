#pragma once

#include <curl/curl.h>
#include <string>

#include "../../interface/exceptions/NetworkException.cpp"

class CurlRestService
{
    CURL * curl;
    CURLcode res;
    std::string hdUrl;

public:
    CurlRestService();
    
    void getNewWallpaperUrl();
};
