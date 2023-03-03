#pragma once

/**
 * @brief destination download directory
 * set this to your preffered directory which you will be using for managing wallpapers
 * 
 */
#define DESTINATION_DIRECTORY "/home/hajekad/.config/awesome/themes/powerarrow-dark/WaSpFolder"

/**
 * @brief image quality selection
 * select high definition picture or normal sized picture
 */
#define URL_TYPE "hdurl"
// #define URL_TYPE "url"


/**
 * @brief shell command
 * write your own prompt to turn .jpg image into a .bmp image
 * default prompt is set to use Image Magick
 */
#define SHELL_JPG_TO_BMP "mogrify -format bmp assets/current.jpg"

/**
 * @brief desired ratio
 * define Width to Height ratio
 * default is set to 16:9
 */
#define WIDTH 16
#define HEIGHT 9
