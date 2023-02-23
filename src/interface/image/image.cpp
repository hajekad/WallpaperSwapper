#include "image.hpp"

Color::Color()
    : r(0), g(0), b(0) {

}

Color::Color(unsigned char r, unsigned char g, unsigned char b)
    : r(r), g(g), b(b) {

}

Color::~Color() {

}

Image::Image(int width, int height)
    : width(width), height(height), colors(std::vector<Color>(width * height)) {

}

Image::~Image() {

}

Color Image::getColor(int x, int y) const {
    return colors[y * width + x];
}

void Image::setColor(const Color & color, int x, int y) {
    colors[y * width + x].r = color.r;
    colors[y * width + x].g = color.g;
    colors[y * width + x].b = color.b;
}

void Image::save(const char * path) const {
    std::ofstream os;
    os.open(path, std::ios::out | std::ios::binary);

    if(!os.is_open()) {
        throw std::runtime_error("Could not open file.");
        return;
    }

    unsigned char bmpPad[3] = {0, 0, 0};
    const int paddingAmount = (4 - (width * 3) % 4) % 4;

    const int fileHeaderSize = 14;
    const int informationHeaderSize = 40;
    const int fileSize = fileHeaderSize + informationHeaderSize + width * height * 3 + paddingAmount * height;

    unsigned char fileHeader[fileHeaderSize];

    fileHeader[0] = 66;
    fileHeader[1] = 77;
    fileHeader[2] = fileSize;
    fileHeader[3] = fileSize >> 8;
    fileHeader[4] = fileSize >> 16;
    fileHeader[5] = fileSize >> 24;
    fileHeader[6] = 0;
    fileHeader[7] = 0;
    fileHeader[8] = 0;
    fileHeader[9] = 0;
    fileHeader[10] = 0;
    fileHeader[11] = 0;
    fileHeader[12] = 0;
    fileHeader[13] = 0;

    unsigned char informationHeader[informationHeaderSize];

    informationHeader[0] = informationHeaderSize;
    informationHeader[1] = 0;
    informationHeader[2] = 0;
    informationHeader[3] = 0;

    informationHeader[4] = width;
    informationHeader[5] = width >> 8;
    informationHeader[6] = width >> 16;
    informationHeader[7] = width >> 24;
    informationHeader[8] = height;
    informationHeader[9] = height >> 8;
    informationHeader[10] = height >> 16;
    informationHeader[11] = height >> 24;
    informationHeader[12] = 1;
    informationHeader[13] = 0;
    informationHeader[14] = 24;
    informationHeader[15] = 0;
    informationHeader[16] = 0;
    informationHeader[17] = 0;
    informationHeader[18] = 0;
    informationHeader[19] = 0;
    informationHeader[20] = 0;
    informationHeader[21] = 0;
    informationHeader[22] = 0;
    informationHeader[23] = 0;
    informationHeader[24] = 0;
    informationHeader[25] = 0;
    informationHeader[26] = 0;
    informationHeader[27] = 0;
    informationHeader[28] = 0;
    informationHeader[29] = 0;
    informationHeader[30] = 0;
    informationHeader[31] = 0;
    informationHeader[32] = 0;
    informationHeader[33] = 0;
    informationHeader[34] = 0;
    informationHeader[35] = 0;
    informationHeader[36] = 0;
    informationHeader[37] = 0;
    informationHeader[38] = 0;
    informationHeader[39] = 0;

    os.write(reinterpret_cast<char *>(fileHeader), fileHeaderSize);
    os.write(reinterpret_cast<char *>(informationHeader), informationHeaderSize);

    for(int y = 0; y < height; y++) {
        for(int x = 0; x < width; x++) {
            auto currColor = getColor(x, y);

            unsigned char tmp[] = {currColor.r, currColor.g, currColor.b};
            os.write(reinterpret_cast<char *>(tmp), 3);
        }
        os.write(reinterpret_cast<char *>(bmpPad), paddingAmount);
    }

    os.close();

    std::cout << "created" << std::endl;
}
