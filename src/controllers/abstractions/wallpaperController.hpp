#pragma once

#include <filesystem>
#include <chrono>
#include <iostream>

#include "../../interface/exceptions/IsRelevantException.cpp"
#include "../../interface/exceptions/NetworkException.cpp"
#include "../../interface/exceptions/SystemException.cpp"

#define SOURCE_PATH "assets/current.jpg"

namespace fs = std::filesystem;

class WallpaperController {
    bool exists(const fs::path & p, fs::file_status s = fs::file_status{});
public:
    void checkRelevance();
    void getNewWallpaper();
    void setNewWallpaper();
};
