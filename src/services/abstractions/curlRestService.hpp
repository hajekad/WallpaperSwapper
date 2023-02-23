#pragma once

#include <curl/curl.h>
#include <string>
#include <cstring>
#include <iostream>

#include "../../interface/exceptions/NetworkException.cpp"

#define KEY_URL "https://api.nasa.gov/planetary/apod?api_key=3uALHm6PeNktClBFYS2DQgTi1cYM1FoYCzwI9SGa"

const std::string URL_TYPE = "hdurl";
// const std::string URL_TYPE = "url"; // sekect this for low quality images

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
