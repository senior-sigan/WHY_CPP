#ifndef WHYCPP_DRAWING_H
#define WHYCPP_DRAWING_H

#include <whycpp/color.h>

class Context;

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
void DrawRectFill(Context &context, int x, int y, int w, int h, const RGBA &color);
void DrawRect(Context &context, int x, int y, int w, int h, const RGBA &color);

#endif //WHYCPP_DRAWING_H
