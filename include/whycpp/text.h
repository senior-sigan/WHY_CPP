#ifndef WHYCPP_TEXT_H
#define WHYCPP_TEXT_H

#include <string>
#include <whycpp/font.h>

class Context;
struct RGBA;

/**
 * @defgroup Text
 * @ingroup WHYCPP_PublicAPI
 * @brief Functions to print texts on the screen
 *
 * @{
 */

/**
 * Prints a single char at a position with color
 * @param ctx
 * @param ch is a symbol to print
 * @param x
 * @param y
 * @param color
 * @param size
 * @param font
 */
void Print(Context& ctx, char ch, int x, int y, const RGBA &color, int size = 1);

/**
 * Prints a string at a position with color
 * @param ctx
 * @param str is a string to print
 * @param x
 * @param y
 * @param color
 * @param size
 * @param spacing is a distance between chars in the string
 * @param font
 */
void Print(Context& ctx, const std::string& str, int x, int y, const RGBA &color, int size = 1, int spacing = 0);

/**
 * @}
 */

#endif //WHYCPP_TEXT_H
