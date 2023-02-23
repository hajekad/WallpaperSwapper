#pragma once

#include <vector>
#include <iostream>
#include <fstream>

struct Color
{
    unsigned char r, g, b; 

    Color();
    Color(unsigned char r, unsigned char g, unsigned char b);
    ~Color();
};

struct Image
{
    int width;
    int height;
    std::vector<Color> colors;

    Image(int width, int height);
    ~Image();

    Color getColor(int x, int y) const;
    void setColor(const Color & color, int x, int y);

    void save(const char * path) const;
};
