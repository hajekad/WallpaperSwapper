#include "../abstractions/curlRestService.hpp"

CurlRestService::CurlRestService() {
    curl = curl_easy_init();
    curl_global_init(CURL_GLOBAL_ALL);
    hdUrl = "";
}

void CurlRestService::getNewWallpaperUrl() {
    if(!curl) {
        throw NetworkException("Could not instantiate curl service.");
    }

    curl_easy_setopt(curl, CURLOPT_URL, "https://api.nasa.gov/planetary/apod?api_key=3uALHm6PeNktClBFYS2DQgTi1cYM1FoYCzwI9SGa");
    
    CURLcode res = curl_easy_perform(curl);

    if(res != CURLE_OK) {
        throw NetworkException(curl_easy_strerror(res));
    }

    curl_easy_cleanup(curl);
}