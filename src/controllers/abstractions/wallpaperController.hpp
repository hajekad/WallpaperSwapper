#pragma once

#include <filesystem>
#include <chrono>
#include <iostream>
#include <fstream>

#include "../../services/abstractions/curlRestService.hpp"

#include "../../../config.hpp"
#include "../../interface/exceptions/IsRelevantException.cpp"
#include "../../interface/exceptions/SystemException.cpp"

#define SOURCE_PATH "assets/current.jpg"
#define TWELVE_HOURS_IN_SECONDS 43200

namespace fs = std::filesystem;

class WallpaperController {
    std::string destinationDirectory = DESTINATION_DIRECTORY;

    void sameDay(const long & now, const long & downloadDate);
public:
    void checkRelevance();

    void getNewWallpaper();

    void setNewWallpaper();
};
