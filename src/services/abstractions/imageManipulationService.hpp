#pragma once

#include <fstream>
#include <iostream>
#include <filesystem>
#include <cstring>

#include "../../interface/bmpImage/bmpImage.hpp"
#include "../../interface/exceptions/SystemException.cpp"

class ImageManipulationService
{
    int width;
    int height;
    std::string sourcePath;
    size_t sourceSize;

public:
    ImageManipulationService(const std::string & sourcePath);

    void setWHRatio();

    void expandImage();
};
