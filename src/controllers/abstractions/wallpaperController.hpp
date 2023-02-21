#pragma once

#include "../../interface/exceptions/IsRelevantException.cpp"
#include "../../interface/exceptions/NetworkException.cpp"
#include "../../interface/exceptions/SystemException.cpp"

class WallpaperController {
public:
    void checkRelevance();
    void getNewWallpaper();
    void setNewWallpaper();
};
