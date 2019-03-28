//
// Created by kirill on 28.03.19.
//

#ifndef WHYCPP_ROOT_DRAWING_H
#define WHYCPP_ROOT_DRAWING_H

#include "color.h"
#include "context.h"
#include "c_api.h"

/**
 *
 * @param context
 * @return display width in pixels
 */
WHYCPP_C_API
int GetDisplayWidth_C(Context_t* context);
/**
 *
 * @param context
 * @return display height in pixels
 */
WHYCPP_C_API
int GetDisplayHeight_C(Context_t* context);
/**
 * Set the pixel color at the [x,y] position
 * @param context of the application
 * @param x coordinate of the pixel on the screen
 * @param y coordinate of the pixel on the screen
 * @param color of the pixel
 */
WHYCPP_C_API
void SetPixel_C(Context_t* context, int x, int y, RGBA_t color);
/**
 * Get the pixel color at the [x,y] position
 * @param context  of the application
 * @param x coordinate of the pixel on the screen
 * @param y coordinate of the pixel on the screen
 * @return color of the pixel
 */
WHYCPP_C_API
RGBA_t GetPixel_C(Context_t* context, int x, int y);
/**
 * Fill the screen with a solid color
 * @param context
 * @param color to fill the screen
 */
WHYCPP_C_API
void DrawClearScreen_C(Context_t* context, RGBA_t color);
/**
 * Draw line on the screen from the [x0,y0] to the [x1,y1] with a color.
 * @param context
 * @param x0 coordinate of the first point
 * @param y0 coordinate of the first point
 * @param x1 coordinate of the second point
 * @param y1 coordinate of the second point
 * @param color of the line
 */
WHYCPP_C_API
void DrawLine_C(Context_t* context, int x0, int y0, int x1, int y1, RGBA_t color);
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
WHYCPP_C_API
void DrawRectFill_C(Context_t* context, int x, int y, int w, int h, RGBA_t color);
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
WHYCPP_C_API
void DrawRect_C(Context_t* context, int x, int y, int w, int h, RGBA_t color);
/**
 * Draw a circle border with the color.
 * Circle body is transparent
 *
 * @param context
 * @param x coordinate of the circle's center
 * @param y coordinate of the circle's center
 * @param radius
 * @param color
 *
 * @see DrawCircleFill()
 */
WHYCPP_C_API
void DrawCircle_C(Context_t* context, int x, int y, int radius, RGBA_t color);
/**
 * Draw a circle border with the color.
 * Circle body is filled with the same color as the border.
 *
 *
 * @param context
 * @param x coordinate of the circle's center
 * @param y coordinate of the circle's center
 * @param radius
 * @param color
 *
 * @see DrawCircle()
 */
WHYCPP_C_API
void DrawCircleFill_C(Context_t* context, int x, int y, int radius, RGBA_t color);

WHYCPP_C_API
void DrawSprite_C(Context_t* context, int sprite_id, int screen_x, int screen_y, int sheet_x, int sheet_y, int width,
                  int height);

#endif  // WHYCPP_ROOT_DRAWING_H
