#include "../abstractions/curlRestService.hpp"

CurlRestService::CurlRestService() {
    curl = curl_easy_init();
}

size_t CurlRestService::writeCallback(void *ptr, size_t size, size_t nmemb, void *userdata) {
    size_t realsize = size * nmemb;
    std::string *response = static_cast<std::string*>(userdata);
    response->append(static_cast<char*>(ptr), realsize);
    return realsize;
}

void CurlRestService::getNewWallpaperUrl() {
    if(!curl) {
        throw NetworkException("Could not instantiate curl service.");
    }

    curl_easy_setopt(curl, CURLOPT_URL, "https://api.nasa.gov/planetary/apod?api_key=3uALHm6PeNktClBFYS2DQgTi1cYM1FoYCzwI9SGa");

    char buffer[CURL_MAX_WRITE_SIZE];

    // curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, CurlRestService::writeCallback);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &hdUrl);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, buffer);

    res = curl_easy_perform(curl);

    if(res != CURLE_OK) {
        throw NetworkException(curl_easy_strerror(res));
    }

    curl_easy_cleanup(curl);
}