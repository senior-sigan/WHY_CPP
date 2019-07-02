#pragma once

#include <whycpp/color.h>
#include <whycpp/types.h>

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
i32 GetDisplayWidth(const Context &context);
/**
 *
 * @param context
 * @return display height in pixels
 */
i32 GetDisplayHeight(const Context &context);
/**
 * Set the pixel color at the [x,y] position
 * @param context of the application
 * @param x coordinate of the pixel on the screen
 * @param y coordinate of the pixel on the screen
 * @param color of the pixel
 */
void SetPixel(Context &context, i32 x, i32 y, const RGBA &color);
/**
 * Get the pixel color at the [x,y] position
 * @param context  of the application
 * @param x coordinate of the pixel on the screen
 * @param y coordinate of the pixel on the screen
 * @return color of the pixel
 */
const RGBA GetPixel(const Context &context, i32 x, i32 y);
/**
 * Fill the screen with a solid color
 * @param context
 * @param color to fill the screen
 */
void DrawClearScreen(Context &context, const RGBA &color = {0, 0, 0, 255});
/**
 * Draw line on the screen from the [x0,y0] to the [x1,y1] with a color.
 * @param context
 * @param x0 coordinate of the first point
 * @param y0 coordinate of the first point
 * @param x1 coordinate of the second point
 * @param y1 coordinate of the second point
 * @param color of the line
 */
void DrawLine(Context &context, i32 x0, i32 y0, i32 x1, i32 y1, const RGBA &color);
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
void DrawRectFill(Context &context, i32 x, i32 y, i32 w, i32 h, const RGBA &color);
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
void DrawRect(Context &context, i32 x, i32 y, i32 w, i32 h, const RGBA &color);
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
void DrawCircle(Context &context, i32 x, i32 y, i32 radius, const RGBA &color);
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
void DrawCircleFill(Context &context, i32 x, i32 y, i32 radius, const RGBA &color);

void DrawSprite(Context &context, i32 sprite_id, i32 screen_x, i32 screen_y, i32 sheet_x, i32 sheet_y, i32 width,
                i32 height);
/** @} */
