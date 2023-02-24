#include <stdexcept>
#include <iostream>

#include "controllers/abstractions/wallpaperController.hpp"

signed main(void) {
    WallpaperController wallpaperController;

    try {
        wallpaperController.checkRelevance();
        wallpaperController.getNewWallpaper();
        // wallpaperController.cropAndCombine();
        wallpaperController.setNewWallpaper();
    } catch (const IsRelevantException & exceptRelevant) {
        std::cerr << "Exception: " << exceptRelevant.what() << std::endl;
    } catch (const NetworkException & exceptNetwork) {
        std::cerr << "Exception: " << exceptNetwork.what() << std::endl;
    } catch (const SystemException & exceptSystem) {
        std::cerr << "Exception: " << exceptSystem.what() << std::endl;
    }catch (const std::runtime_error & e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    } catch (...) {
        return EXIT_FAILURE;
    } 

    return EXIT_SUCCESS;
}
