#include <stdexcept>
#include <iostream>

#include "controllers/abstractions/wallpaperController.hpp"

signed main(void) {
    WallpaperController wallpaperController;

    try {
        wallpaperController.checkRelevance();
        wallpaperController.getNewWallpaper();
        wallpaperController.setNewWallpaper();
    } catch (const IsRelevantException & exceptRelevant) {
        std::cerr << "Exception: Image is still relevant" << std::endl;
    } catch (const NetworkException & exceptNetwork) {
        std::cerr << "Exception: " << exceptNetwork.what() << std::endl;
    } catch (const SystemException & exceptSystem) {
        std::cerr << "Exception: " << exceptSystem.what() << std::endl;
    } 

    return EXIT_SUCCESS;
}