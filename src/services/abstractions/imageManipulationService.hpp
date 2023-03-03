#pragma once

#include <fstream>
#include <iostream>
#include <filesystem>
#include <cstring>
#include <memory>

#include "../../../config.hpp"
#include "../../interface/bmpImage/bmpImage.hpp"
#include "../../interface/exceptions/SystemException.cpp"

class ImageManipulationService
{
    std::unique_ptr<BmpImage> source;
    std::string sourcePath;
    size_t sourceSize;

public:
    ImageManipulationService(const std::string & sourcePath);

    void expandImage();
};
