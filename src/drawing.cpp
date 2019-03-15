#include <whycpp/drawing.h>
#include "context.h"
#include <algorithm>
#include "video_memory.h"
#include <whycpp/color.h>
#include <iostream>

int GetDisplayWidth(const Context &ctx) {
  return ctx.GetVRAM()->GetWidth();
}
int GetDisplayHeight(const Context &ctx) {
  return ctx.GetVRAM()->GetHeight();
}
void SetPixel(Context &ctx, int x, int y, const RGBA &color) {
  if (color.alpha == 0)
    return;
  ctx.GetVRAM()->Set(x, y, color);
}
const RGBA GetPixel(const Context &ctx, int x, int y) {
  return ctx.GetVRAM()->Get(x, y);
}
void DrawClearScreen(Context &ctx, const RGBA &color) {
  for (int x = 0; x < GetDisplayWidth(ctx); x++) {
    for (int y = 0; y < GetDisplayHeight(ctx); y++) {
      SetPixel(ctx, x, y, color);
    }
  }
}
void DrawLine(Context &ctx, int x0, int y0, int x1, int y1, const RGBA &color) {
  int dx = std::abs(x1 - x0), sx = x0 < x1 ? 1 : -1;
  int dy = std::abs(y1 - y0), sy = y0 < y1 ? 1 : -1;
  int err = (dx > dy ? dx : -dy) / 2;
  int e2;

  for (;;) {
    SetPixel(ctx, x0, y0, color);
    if (x0 == x1 && y0 == y1) break;
    e2 = err;
    if (e2 > -dx) {
      err -= dy;
      x0 += sx;
    }
    if (e2 < dy) {
      err += dx;
      y0 += sy;
    }
  }
}
void DrawRectFill(Context &ctx, int x, int y, int w, int h, const RGBA &color) {
  for (auto i = y; i < y + h; i++) {
    DrawLine(ctx, x, i, x + w - 1, i, color);
  }
}
void DrawRect(Context &ctx, int x, int y, int w, int h, const RGBA &color) {
  DrawLine(ctx, x, y, x + w, y, color);
  DrawLine(ctx, x, y, x, y + h, color);

  DrawLine(ctx, x + w, y, x + w, y + h, color);
  DrawLine(ctx, x, y + h, x + w, y + h, color);
}
void DrawCircle(Context &context, int x, int y, int radius, const RGBA &color) {
  int r = radius;
  int x_ = -r;
  int y_ = 0;
  int err = 2 - 2 * r;
  do {
    SetPixel(context, x - x_, y + y_, color);
    SetPixel(context, x + x_, y - y_, color);

    SetPixel(context, x - y_, y - x_, color);
    SetPixel(context, x + y_, y + x_, color);
    r = err;
    if (r <= y_) err += ++y_ * 2 + 1;
    if (r > x_ || err > y_) err += ++x_ * 2 + 1;
  } while (x_ < 0);
}
void DrawCircleFill(Context &context, int x, int y, int radius, const RGBA &color) {
  int r = radius;
  int x_ = -r;
  int y_ = 0;
  int err = 2 - 2 * r;
  do {
    for (int i = x + x_; i <= x - x_; i++) {
      SetPixel(context, i, y + y_, color);
    }
    for (int i = x + x_; i <= x - x_; i++) {
      SetPixel(context, i, y - y_, color);
    }

    r = err;
    if (r <= y_) err += ++y_ * 2 + 1;
    if (r > x_ || err > y_) err += ++x_ * 2 + 1;
  } while (x_ < 0);
}

void DrawSprite(Context &context,
                int sprite_id,
                int screen_x,
                int screen_y,
                int sheet_x,
                int sheet_y,
                int width,
                int height) {
  auto spr = context.GetSprite(sprite_id);
  for (auto y = 0; y < height; y++) {
    for (auto x = 0; x < width; x++) {
      SetPixel(context, screen_x + x, screen_y + y, spr->Get(sheet_x + x, sheet_y + y));
    }
  }
}