#include <stdexcept>
#include <iostream>

#include "controllers/abstractions/wallpaperController.hpp"
#include "interface/exceptions/IsRelevantException.cpp"
#include "interface/exceptions/NetworkException.cpp"
#include "interface/exceptions/SystemException.cpp"

signed main(void) {
    WallpaperController wallpaperController;

    try {
        wallpaperController.checkRelevance();
        wallpaperController.getNewWallpaper();
        wallpaperController.setNewWallpaper();
    } catch (IsRelevantException exceptRelevant) {
        std::cerr << "Exception: Image is still relevant" << std::endl;
    } catch (NetworkException exceptNetwork) {
        std::cerr << "Exception: " << exceptNetwork.what() << std::endl;
    } catch (SystemException exceptSystem) {
        std::cerr << "Exception: " << exceptSystem.what() << std::endl;
    } 

    return EXIT_SUCCESS;
}