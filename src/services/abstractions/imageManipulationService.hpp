#pragma once

#include <fstream>
#include <iostream>
#include <filesystem>

#include "../../interface/image/image.hpp"
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
