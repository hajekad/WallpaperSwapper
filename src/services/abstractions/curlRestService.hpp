#pragma once

#include <curl/curl.h>
#include <string>

class CurlRestService
{
    CURL * curl;
    CURLcode res;
public:
    CurlRestService();
};
