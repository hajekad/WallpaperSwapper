#pragma once

#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

struct Color
{
    unsigned char r, g, b; 

    Color();
    Color(unsigned char r, unsigned char g, unsigned char b);
    ~Color();
};

struct BmpImage
{
    int width;
    int height;
    std::vector<Color> colors;

    BmpImage(const char * path);
    BmpImage(int width, int height);
    ~BmpImage();

    Color getColor(int x, int y) const;
    void setColor(const Color & color, int x, int y);

    void save(const char * path) const;
};
