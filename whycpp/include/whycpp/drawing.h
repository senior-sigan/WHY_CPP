#ifndef WHYCPP_DRAWING_H
#define WHYCPP_DRAWING_H

#include <whycpp/color.h>

/**
 * @defgroup Drawing
 * @ingroup WHYCPP_PublicAPI
 * @brief Functions to draw something on the screen
 *
 * @{
 */

/**
 *
 * @return display width in pixels
 */
int GetDisplayWidth();
/**
 *
 * @return display height in pixels
 */
int GetDisplayHeight();
/**
 * Set the pixel color at the [x,y] position
 * @param x coordinate of the pixel on the screen
 * @param y coordinate of the pixel on the screen
 * @param color of the pixel
 */
void SetPixel(int x, int y, const RGBA &color);
/**
 * Get the pixel color at the [x,y] position
 * @param x coordinate of the pixel on the screen
 * @param y coordinate of the pixel on the screen
 * @return color of the pixel
 */
const RGBA GetPixel(int x, int y);
/**
 * Fill the screen with a solid color
 * @param color to fill the screen
 */
void DrawClearScreen(const RGBA &color = {0, 0, 0, 255});
/**
 * Draw line on the screen from the [x0,y0] to the [x1,y1] with a color.
 * @param x0 coordinate of the first point
 * @param y0 coordinate of the first point
 * @param x1 coordinate of the second point
 * @param y1 coordinate of the second point
 * @param color of the line
 */
void DrawLine(int x0, int y0, int x1, int y1, const RGBA &color);
/**
 * Draw a rectangle and fill it with color.
 * To draw it you need a left-upper corner coordinates [x,y] and rectangle width and height.
 * @param x coordinate of the left-upper corner
 * @param y coordinate of the left-upper corner
 * @param w width of the rectangle to draw
 * @param h width of the rectangle to draw
 * @param color of the borders and filler
 * @see DrawRect()
 */
void DrawRectFill(int x, int y, int w, int h, const RGBA &color);
/**
 * Draw a rectangle borders with the color.
 * Rectangle body is transparent.
 *
 * To draw it you need a left-upper corner coordinates [x,y] and rectangle width and height.
 * @param x coordinate of the left-upper corner
 * @param y coordinate of the left-upper corner
 * @param w width of the rectangle to draw
 * @param h width of the rectangle to draw
 * @param color of the borders and filler
 *
 * @see DrawRectFill()
 */
void DrawRect(int x, int y, int w, int h, const RGBA &color);
/**
 * Draw a circle border with the color.
 * Circle body is transparent
 * @param x coordinate of the circle's center
 * @param y coordinate of the circle's center
 * @param radius
 * @param color
 *
 * @see DrawCircleFill()
 */
void DrawCircle(int x, int y, int radius, const RGBA &color);
/**
 * Draw a circle border with the color.
 * Circle body is filled with the same color as the border.
 * @param x coordinate of the circle's center
 * @param y coordinate of the circle's center
 * @param radius
 * @param color
 *
 * @see DrawCircle()
 */
void DrawCircleFill(int x, int y, int radius, const RGBA &color);

void DrawSprite(int sprite_id, int screen_x, int screen_y, int sheet_x, int sheet_y, int width, int height);
/** @} */

#endif  // WHYCPP_DRAWING_H
