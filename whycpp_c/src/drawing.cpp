//
// Created by kirill on 28.03.19.
//

#include <whycpp/drawing.h>
#include <whycpp_c/drawing.h>

int GetDisplayWidth_C(Context_t *context) {
  return GetDisplayWidth(*reinterpret_cast<Context *>(context));
}
int GetDisplayHeight_C(Context_t *context) {
  return GetDisplayHeight(*reinterpret_cast<Context *>(context));
}
void SetPixel_C(Context_t *context, int x, int y, RGBA_t color) {
  SetPixel(*reinterpret_cast<Context *>(context), x, y,
           {color.rgba.red, color.rgba.green, color.rgba.blue, color.rgba.alpha});
}
RGBA_t GetPixel_C(Context_t *context, int x, int y) {
  RGBA color = GetPixel(*reinterpret_cast<Context *>(context), x, y);
  RGBA_t result;
  result.rgba.red = color.red;
  result.rgba.green = color.green;
  result.rgba.blue = color.blue;
  result.rgba.alpha = color.alpha;
  return result;
}
void DrawClearScreen_C(Context_t *context, RGBA_t color) {}
void DrawLine_C(Context_t *context, int x0, int y0, int x1, int y1, RGBA_t color) {}
void DrawRectFill_C(Context_t *context, int x, int y, int w, int h, RGBA_t color) {}
void DrawRect_C(Context_t *context, int x, int y, int w, int h, RGBA_t color) {}
void DrawCircle_C(Context_t *context, int x, int y, int radius, RGBA_t color) {}
void DrawCircleFill_C(Context_t *context, int x, int y, int radius, RGBA_t color) {}
void DrawSprite_C(Context_t *context, int sprite_id, int screen_x, int screen_y, int sheet_x, int sheet_y, int width,
                  int height) {}
