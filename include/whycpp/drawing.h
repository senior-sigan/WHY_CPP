#ifndef WHYCPP_DRAWING_H
#define WHYCPP_DRAWING_H

#include <whycpp/color.h>

class Context;

/**
 * @defgroup Drawing
 * @ingroup WHYCPP_PublicAPI
 * @brief Functions to draw something on the screen
 *
 * @{
 */

/**
 *
 * @param context
 * @return display width in pixels
 */
int GetDisplayWidth(const Context &context);
/**
 *
 * @param context
 * @return display height in pixels
 */
int GetDisplayHeight(const Context &context);
/**
 * Set the pixel color at the [x,y] position
 * @param context of the application
 * @param x coordinate of the pixel on the screen
 * @param y coordinate of the pixel on the screen
 * @param color of the pixel
 */
void SetPixel(Context &context, int x, int y, const RGBA &color);
/**
 * Get the pixel color at the [x,y] position
 * @param context  of the application
 * @param x coordinate of the pixel on the screen
 * @param y coordinate of the pixel on the screen
 * @return color of the pixel
 */
const RGBA GetPixel(const Context &context, int x, int y);
/**
 * Fill the screen with a solid color
 * @param context
 * @param color to fill the screen
 */
void DrawClearScreen(Context &context, const RGBA &color = {0, 0, 0, 0});
/**
 * Draw line on the screen from the [x0,y0] to the [x1,y1] with a color.
 * @param context
 * @param x0 coordinate of the first point
 * @param y0 coordinate of the first point
 * @param x1 coordinate of the second point
 * @param y1 coordinate of the second point
 * @param color of the line
 */
void DrawLine(Context &context, int x0, int y0, int x1, int y1, const RGBA &color);
/**
 * Draw a rectangle and fill it with color.
 * To draw it you need a left-upper corner coordinates [x,y] and rectangle width and height.
 * @param context
 * @param x coordinate of the left-upper corner
 * @param y coordinate of the left-upper corner
 * @param w width of the rectangle to draw
 * @param h width of the rectangle to draw
 * @param color of the borders and filler
 * @see DrawRect()
 */
void DrawRectFill(Context &context, int x, int y, int w, int h, const RGBA &color);
/**
 * Draw a rectangle borders with the color.
 * Rectangle body is transparent.
 *
 * To draw it you need a left-upper corner coordinates [x,y] and rectangle width and height.
 * @param context
 * @param x coordinate of the left-upper corner
 * @param y coordinate of the left-upper corner
 * @param w width of the rectangle to draw
 * @param h width of the rectangle to draw
 * @param color of the borders and filler
 *
 * @see DrawRectFill()
 */
void DrawRect(Context &context, int x, int y, int w, int h, const RGBA &color);

/** @} */

#endif //WHYCPP_DRAWING_H
