#pragma once

#include <whycpp/font.h>
#include <whycpp/types.h>
#include <string>

class Context;
struct RGBA;

/**
 * @defgroup Text
 * @ingroup WHYCPP_PublicAPI
 * @brief Functions to pri32 texts on the screen
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
void Print(Context& ctx, char ch, i32 x, i32 y, const RGBA& color, i32 size = 1);

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
void Print(Context& ctx, const std::string& str, i32 x, i32 y, const RGBA& color, i32 size = 1, i32 spacing = 0);

/**
 * @}
 */
