//
// Created by kirill on 28.03.19.
//

#include <whycpp/drawing.h>
#include <whycpp_c/drawing.h>
#include "internal/drawing_int.h"
#include "internal/global_context_int.h"

int GetDisplayWidth_C() {
  return GetDisplayWidth(*GetContext_C());
}

int GetDisplayHeight_C() {
  return GetDisplayHeight(*GetContext_C());
}

void SetPixel_C(int x, int y, RGBA_t color) {
  SetPixel(*GetContext_C(), x, y, to_Cpp(color));
}

RGBA_t GetPixel_C(int x, int y) {
  RGBA color = GetPixel(*GetContext_C(), x, y);
  return to_C(color);
}

void DrawClearScreen_C(RGBA_t color) {
  DrawClearScreen(*GetContext_C(), to_Cpp(color));
}

void DrawLine_C(int x0, int y0, int x1, int y1, RGBA_t color) {
  DrawLine(*GetContext_C(), x0, y0, x1, y1, to_Cpp(color));
}

void DrawRectFill_C(int x, int y, int w, int h, RGBA_t color) {
  DrawRectFill(*GetContext_C(), x, y, w, h, to_Cpp(color));
}

void DrawRect_C(int x, int y, int w, int h, RGBA_t color) {
  DrawRect(*GetContext_C(), x, y, w, h, to_Cpp(color));
}

void DrawCircle_C(int x, int y, int radius, RGBA_t color) {
  DrawCircle(*GetContext_C(), x, y, radius, to_Cpp(color));
}

void DrawCircleFill_C(int x, int y, int radius, RGBA_t color) {
  DrawCircleFill(*GetContext_C(), x, y, radius, to_Cpp(color));
}

void DrawSprite_C(int sprite_id, int screen_x, int screen_y, int sheet_x, int sheet_y, int width, int height) {
  DrawSprite(*GetContext_C(), sprite_id, screen_x, screen_y, sheet_x, sheet_y, width, height);
}
