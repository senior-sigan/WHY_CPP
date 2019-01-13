#ifndef WHYCPP_DRAWING_H
#define WHYCPP_DRAWING_H

#include <cstdint>

class Context;
struct RGBA;

int GetDisplayWidth(const Context &ctx);
int GetDisplayHeight(const Context &ctx);

void SetPixel(Context &ctx, int x, int y, const RGBA &color);
const RGBA GetPixel(const Context &ctx, int x, int y);

void DrawClearScreen(Context &ctx);
void DrawLine(Context &ctx, int x0, int y0, int x1, int y1, const RGBA &color);
void DrawRectFill(Context &ctx, int x, int y, int w, int h, const RGBA &color);
void DrawRect(Context &ctx, int x, int y, int w, int h, const RGBA &color);

#endif //WHYCPP_DRAWING_H
