#include <whycpp/color.h>
#include <whycpp/drawing.h>
#include <algorithm>
#include "context.h"
#include "global_app_context.h"
#include "sprite.h"
#include "video_memory.h"

int GetDisplayWidth() {
  return GetContext().GetVRAM()->GetWidth();
}
int GetDisplayHeight() {
  return GetContext().GetVRAM()->GetHeight();
}
void SetPixel(int x, int y, const RGBA &color) {
  if (color.alpha == 0) return;
  GetContext().GetVRAM()->Set(x, y, color);
}
const RGBA GetPixel(int x, int y) {
  return GetContext().GetVRAM()->Get(x, y);
}
void DrawClearScreen(const RGBA &color) {
  GetContext().GetVRAM()->Fill(color);
}
void DrawLine(int x0, int y0, int x1, int y1, const RGBA &color) {
  int dx = std::abs(x1 - x0), sx = x0 < x1 ? 1 : -1;
  int dy = std::abs(y1 - y0), sy = y0 < y1 ? 1 : -1;
  int err = (dx > dy ? dx : -dy) / 2;
  int e2;

  for (;;) {
    SetPixel(x0, y0, color);
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
void DrawRectFill(int x, int y, int w, int h, const RGBA &color) {
  for (auto i = y; i < y + h; i++) {
    DrawLine(x, i, x + w - 1, i, color);
  }
}
void DrawRect(int x, int y, int w, int h, const RGBA &color) {
  DrawLine(x, y, x + w, y, color);
  DrawLine(x, y, x, y + h, color);

  DrawLine(x + w, y, x + w, y + h, color);
  DrawLine(x, y + h, x + w, y + h, color);
}
void DrawCircle(int x, int y, int radius, const RGBA &color) {
  int r = radius;
  int x_ = -r;
  int y_ = 0;
  int err = 2 - 2 * r;
  do {
    SetPixel(x - x_, y + y_, color);
    SetPixel(x + x_, y - y_, color);

    SetPixel(x - y_, y - x_, color);
    SetPixel(x + y_, y + x_, color);
    r = err;
    if (r <= y_) err += ++y_ * 2 + 1;
    if (r > x_ || err > y_) err += ++x_ * 2 + 1;
  } while (x_ < 0);
}
void DrawCircleFill(int x, int y, int radius, const RGBA &color) {
  int r = radius;
  int x_ = -r;
  int y_ = 0;
  int err = 2 - 2 * r;
  do {
    for (int i = x + x_; i <= x - x_; i++) {
      SetPixel(i, y + y_, color);
    }
    for (int i = x + x_; i <= x - x_; i++) {
      SetPixel(i, y - y_, color);
    }

    r = err;
    if (r <= y_) err += ++y_ * 2 + 1;
    if (r > x_ || err > y_) err += ++x_ * 2 + 1;
  } while (x_ < 0);
}

void DrawSprite(int sprite_id, int screen_x, int screen_y, int sheet_x, int sheet_y, int width,
                int height) {
  auto spr = GetContext().GetSprite(sprite_id);
  for (auto y = 0; y < height; y++) {
    for (auto x = 0; x < width; x++) {
      SetPixel(screen_x + x, screen_y + y, spr->Get(sheet_x + x, sheet_y + y));
    }
  }
}