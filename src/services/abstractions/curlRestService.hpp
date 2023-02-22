#pragma once

#include <curl/curl.h>
#include <string>
#include <cstring>
#include <iostream>
#include <fstream>

#include "../../interface/exceptions/NetworkException.cpp"

class CurlRestService
{
    CURL * curl;
    CURLcode res;
    std::string hdUrl;

    void clearHdUrl();
public:
    CurlRestService();
    
    void getNewWallpaperUrl();

    void getNewWallpaperImage();
};
