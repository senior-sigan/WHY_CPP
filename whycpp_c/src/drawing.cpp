//
// Created by kirill on 28.03.19.
//

#include <whycpp/drawing.h>
#include <whycpp_c/drawing.h>

typedef union {
  struct RGBA rgba;
  uint32_t raw;
} RGBA_conv;

RGBA_t to_C(const RGBA &color) {
  RGBA_conv conv;
  RGBA_t result;
  conv.rgba = color;
  result.raw = conv.raw;
  return result;
}

RGBA to_Cpp(RGBA_t color) {
  RGBA_conv conv;
  conv.raw = color.raw;
  return conv.rgba;
}

int GetDisplayWidth_C(Context_t *context) {
  return GetDisplayWidth(*reinterpret_cast<Context *>(context));
}
int GetDisplayHeight_C(Context_t *context) {
  return GetDisplayHeight(*reinterpret_cast<Context *>(context));
}
void SetPixel_C(Context_t *context, int x, int y, RGBA_t color) {
  SetPixel(*reinterpret_cast<Context *>(context), x, y, to_Cpp(color));
}
RGBA_t GetPixel_C(Context_t *context, int x, int y) {
  RGBA color = GetPixel(*reinterpret_cast<Context *>(context), x, y);
  return to_C(color);
}
void DrawClearScreen_C(Context_t *context, RGBA_t color) {
  DrawClearScreen(*reinterpret_cast<Context *>(context), to_Cpp(color));
}
void DrawLine_C(Context_t *context, int x0, int y0, int x1, int y1, RGBA_t color) {
  DrawLine(*reinterpret_cast<Context *>(context), x0, y0, x1, y1, to_Cpp(color));
}
void DrawRectFill_C(Context_t *context, int x, int y, int w, int h, RGBA_t color) {
  DrawRectFill(*reinterpret_cast<Context *>(context), x, y, w, h, to_Cpp(color));
}
void DrawRect_C(Context_t *context, int x, int y, int w, int h, RGBA_t color) {
  DrawRect(*reinterpret_cast<Context *>(context), x, y, w, h, to_Cpp(color));
}
void DrawCircle_C(Context_t *context, int x, int y, int radius, RGBA_t color) {
  DrawCircle(*reinterpret_cast<Context *>(context), x, y, radius, to_Cpp(color));
}
void DrawCircleFill_C(Context_t *context, int x, int y, int radius, RGBA_t color) {
  DrawCircleFill(*reinterpret_cast<Context *>(context), x, y, radius, to_Cpp(color));
}
void DrawSprite_C(Context_t *context, int sprite_id, int screen_x, int screen_y, int sheet_x, int sheet_y, int width,
                  int height) {
  DrawSprite(*reinterpret_cast<Context *>(context), sprite_id, screen_x, screen_y, sheet_x, sheet_y, width, height);
}
