#include "../abstractions/imageManipulationService.hpp"

ImageManipulationService::ImageManipulationService(const std::string & sourcePath) {
    this->sourcePath = sourcePath;
    width = 0;
    height = 0;
    sourceSize = std::filesystem::file_size(sourcePath);
}

inline bool readbyte( int & byte, std::istream & in ) {
    return (byte = in.get()) >= 0;
}

inline bool readword( int& word, std::istream & in ) {
    int cc = 0, dd = 0;
    
    if( (cc = in.get()) < 0 || (dd = in.get()) < 0 ) {
        return false;
    }

    word = (cc << 8) + dd;
    return true;
}

bool scanhead( std::istream & in, int & image_width, int & image_height ) {
    int marker = 0, dummy = 0;

    if ( in.get() != 0xFF || in.get() != 0xD8 ) {
        return 0;
    }

    while (true) {
        int discarded_bytes = 0;
        readbyte(marker, in);

        while (marker != 0xFF) {
            ++discarded_bytes;
            readbyte(marker, in);
        }
        do readbyte(marker, in); while (marker == 0xFF);

        if (discarded_bytes != 0) {
            return 0;
        }
   

        switch (marker) {
            case 0xC0: case 0xC1: case 0xC2: case 0xC3: case 0xC5:
            case 0xC6: case 0xC7: case 0xC9: case 0xCA: case 0xCB:
            case 0xCD: case 0xCE: case 0xCF: {
                readword( dummy, in );    // usual parameter length count
                readbyte( dummy, in );
                readword( image_height, in );
                readword( image_width, in );
                readbyte( dummy, in );

                return true;
            }

            case 0xDA: case 0xD9: {
                return false;
            }

            default: {
                int length;
                readword(length, in);

                if (length < 2) {
                    return 0;
                }
                length -= 2;

                for ( ; length > 0; --length) {
                    readbyte(dummy, in);
                }
            }
        }
    }
}

void ImageManipulationService::setWHRatio() {
    std::ifstream fin(sourcePath);

    if(!scanhead(fin, width, height)) {
        throw SystemException("Error scanning file.");
    }
}

void ImageManipulationService::expandImage() {
    // int newWidth = (height / 9) * 16;
    // int startAt = (newWidth - width) / 2;
    
    // BmpImage image(newWidth, height);
    // image.save("assets/random.jpg");

    // Image source(sourcePath.c_str());
    // source.save("assets/testSave.jpg");
}