#include "../abstractions/wallpaperController.hpp"

void WallpaperController::checkRelevance() {
    std::filesystem::path filePath(SOURCE_PATH);

    if (std::filesystem::exists(filePath))
    {
        const auto fileTime = std::filesystem::last_write_time(filePath);
        const auto systemTime = std::chrono::file_clock::to_sys(fileTime);
        const auto time = std::chrono::system_clock::to_time_t(systemTime);

        std::cout << "Download date: " << time << std::endl;
    }
    else
    {
        throw IsRelevantException("File not found.");
    }
}


void WallpaperController::getNewWallpaper() {
    throw NetworkException("idk");
}


void WallpaperController::setNewWallpaper() {
    throw SystemException("lol");
}