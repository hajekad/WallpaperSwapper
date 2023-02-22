#pragma once

#include <curl/curl.h>
#include <string>
#include <cstring>
#include <iostream>

#include "../../interface/exceptions/NetworkException.cpp"

size_t dataSize = 0;

class CurlRestService
{
    CURL * curl;
    CURLcode res;
    std::string hdUrl;

public:
    CurlRestService();

    void getInfo();
    
    void getNewWallpaperUrl();

    void clearHdUrl();
};
