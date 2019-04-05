//
// Created by k.leyfer on 29.03.2019.
//

#ifndef WHYCPP_ROOT_TEXT_H
#define WHYCPP_ROOT_TEXT_H

#include <whycpp/c_api.h>
#include "color.h"

/**
 * Prints a single char at a position with color
 * @param ch is a symbol to print
 * @param x
 * @param y
 * @param color
 * @param size
 * @param font
 */
WHYCPP_C_API
void PrintChar_C(char ch, int x, int y, RGBA_t color, int size);

/**
 * Prints a string at a position with color
 * @param str is a string to print
 * @param x
 * @param y
 * @param color
 * @param size
 * @param spacing is a distance between chars in the string
 * @param font
 */
WHYCPP_C_API
void PrintStr_C(const char* str, int x, int y, RGBA_t color, int size, int spacing);


#endif //WHYCPP_ROOT_TEXT_H
