#pragma once

#include <filesystem>
#include <chrono>
#include <iostream>

#include "../../interface/exceptions/IsRelevantException.cpp"
#include "../../interface/exceptions/NetworkException.cpp"
#include "../../interface/exceptions/SystemException.cpp"

#define SOURCE_PATH "assets/current.jpg"
#define TWELVE_HOURS_IN_SECONDS 43200

namespace fs = std::filesystem;

class WallpaperController {
    void sameDay(const long & now, const long & downloadDate);
public:
    void checkRelevance();
    void getNewWallpaper();
    void setNewWallpaper();
};
