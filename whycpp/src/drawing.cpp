#include <whycpp/color.h>
#include <whycpp/drawing.h>
#include <whycpp/types.h>
#include <algorithm>
#include "context.h"
#include "holders/sprites_holder.h"
#include "sprite.h"
#include "holders/video_memory_holder.h"

i32 GetDisplayWidth(const Context &ctx) {
  return ctx.Get<VideoMemoryHolder>()->GetWidth();
}
i32 GetDisplayHeight(const Context &ctx) {
  return ctx.Get<VideoMemoryHolder>()->GetHeight();
}
void SetPixel(Context &ctx, i32 x, i32 y, const RGBA &color) {
  if (color.alpha == 0) return;
  ctx.Get<VideoMemoryHolder>()->Set(x, y, color);
}
const RGBA GetPixel(const Context &ctx, i32 x, i32 y) {
  return ctx.Get<VideoMemoryHolder>()->Get(x, y);
}
void DrawClearScreen(Context &ctx, const RGBA &color) {
  ctx.Get<VideoMemoryHolder>()->Fill(color);
}
void DrawLine(Context &ctx, i32 x0, i32 y0, i32 x1, i32 y1, const RGBA &color) {
  i32 dx = std::abs(x1 - x0), sx = x0 < x1 ? 1 : -1;
  i32 dy = std::abs(y1 - y0), sy = y0 < y1 ? 1 : -1;
  i32 err = (dx > dy ? dx : -dy) / 2;
  i32 e2;

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
void DrawRectFill(Context &ctx, i32 x, i32 y, i32 w, i32 h, const RGBA &color) {
  for (auto i = y; i < y + h; i++) {
    DrawLine(ctx, x, i, x + w - 1, i, color);
  }
}
void DrawRect(Context &ctx, i32 x, i32 y, i32 w, i32 h, const RGBA &color) {
  DrawLine(ctx, x, y, x + w, y, color);
  DrawLine(ctx, x, y, x, y + h, color);

  DrawLine(ctx, x + w, y, x + w, y + h, color);
  DrawLine(ctx, x, y + h, x + w, y + h, color);
}
void DrawCircle(Context &context, i32 x, i32 y, i32 radius, const RGBA &color) {
  i32 r = radius;
  i32 x_ = -r;
  i32 y_ = 0;
  i32 err = 2 - 2 * r;
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
void DrawCircleFill(Context &context, i32 x, i32 y, i32 radius, const RGBA &color) {
  i32 r = radius;
  i32 x_ = -r;
  i32 y_ = 0;
  i32 err = 2 - 2 * r;
  do {
    for (i32 i = x + x_; i <= x - x_; i++) {
      SetPixel(context, i, y + y_, color);
    }
    for (i32 i = x + x_; i <= x - x_; i++) {
      SetPixel(context, i, y - y_, color);
    }

    r = err;
    if (r <= y_) err += ++y_ * 2 + 1;
    if (r > x_ || err > y_) err += ++x_ * 2 + 1;
  } while (x_ < 0);
}

void DrawSprite(Context &context, i32 sprite_id, i32 screen_x, i32 screen_y, i32 sheet_x, i32 sheet_y, i32 width,
                i32 height) {
  auto spr = context.Get<SpritesHolder>()->GetSprite(sprite_id);
  for (auto y = 0; y < height; y++) {
    for (auto x = 0; x < width; x++) {
      SetPixel(context, screen_x + x, screen_y + y, spr->Get(sheet_x + x, sheet_y + y));
    }
  }
}
