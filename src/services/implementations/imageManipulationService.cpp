#include "../abstractions/imageManipulationService.hpp"

ImageManipulationService::ImageManipulationService(const std::string & sourcePath) {
    this->sourcePath = sourcePath;
    
    sourceSize = std::filesystem::file_size(sourcePath);

    std::string prompt = "mogrify -format bmp assets/current.jpg";

    std::system(prompt.c_str());
    source = std::make_unique<BmpImage>("assets/current.bmp");
}

void ImageManipulationService::expandImage() {
    if(source->height * 16 < source->width * 9) {
        source->save("assets/new.bmp");
        return;
    }

    int newWidth = (source->height / 9) * 16;
    int startAt =  (newWidth - source->width) / 2;
     
    BmpImage newImage(newWidth, source->height);

    for(int y = 0; y < source->height; y++) {
        for(int x = 0; x < source->width; x++) {
            Color currCol = source->getColor(x, y);
            newImage.setColor(currCol, x + startAt, y);
        }
    }

    newImage.save("assets/new.bmp");
}
