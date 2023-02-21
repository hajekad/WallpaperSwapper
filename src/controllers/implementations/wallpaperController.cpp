#include "../abstractions/wallpaperController.hpp"

void WallpaperController::sameDay(const long & now, const long & downloadDate) {
    if(now - TWELVE_HOURS_IN_SECONDS < downloadDate && now + TWELVE_HOURS_IN_SECONDS > downloadDate) {
        throw IsRelevantException("Still the same day.");
    }
}

void WallpaperController::checkRelevance() {
    std::filesystem::path filePath(SOURCE_PATH);
    std::time_t now = std::time(0);

    if (std::filesystem::exists(filePath))
    {
        const auto fileTime = std::filesystem::last_write_time(filePath);
        const auto systemTime = std::chrono::file_clock::to_sys(fileTime);
        const auto downloadTime = std::chrono::system_clock::to_time_t(systemTime);

        sameDay(now, downloadTime);
    } else {
        throw IsRelevantException("File not found.");
    }
}


void WallpaperController::getNewWallpaper() {
    throw NetworkException("idk");
}


void WallpaperController::setNewWallpaper() {
    throw SystemException("lol");
}