#include <duktape.h>
#include <whycpp/color.h>
#include <whycpp/drawing.h>
#include <whycpp/log.h>
#include "color_helpers.h"
#include "global_app_context.h"

duk_ret_t js_GetDisplayWidth(duk_context *ctx) {
  auto w = GetDisplayWidth(GetGlobalContext());
  duk_push_number(ctx, w);
  return 1;
}
duk_ret_t js_GetDisplayHeight(duk_context *ctx) {
  auto h = GetDisplayHeight(GetGlobalContext());
  duk_push_number(ctx, h);
  return 1;
}
duk_ret_t js_SetPixel(duk_context *ctx) {
  auto x = duk_to_int(ctx, 0);
  auto y = duk_to_int(ctx, 1);
  auto color = GetColor(ctx, 2);
  SetPixel(GetGlobalContext(), x, y, color);
  return 0;
}
duk_ret_t js_GetPixel(duk_context *ctx) {
  auto x = duk_to_int(ctx, 0);
  auto y = duk_to_int(ctx, 1);
  auto color = GetPixel(GetGlobalContext(), x, y);
  PutColor(ctx, color);
  return 1;
}
duk_ret_t js_DrawClearScreen(duk_context *ctx) {
  auto color = GetColor(ctx, 0);
  DrawClearScreen(GetGlobalContext(), color);
  return 0;
}
duk_ret_t js_DrawLine(duk_context *ctx) {
  auto x0 = duk_to_int(ctx, 0);
  auto y0 = duk_to_int(ctx, 1);
  auto x1 = duk_to_int(ctx, 2);
  auto y1 = duk_to_int(ctx, 3);
  auto color = GetColor(ctx, 4);
  DrawLine(GetGlobalContext(), x0, y0, x1, y1, color);
  return 0;
}
duk_ret_t js_DrawRectFill(duk_context *ctx) {
  auto x = duk_to_int(ctx, 0);
  auto y = duk_to_int(ctx, 1);
  auto w = duk_to_int(ctx, 2);
  auto h = duk_to_int(ctx, 3);
  auto color = GetColor(ctx, 4);

  DrawRectFill(GetGlobalContext(), x, y, w, h, color);
  return 0;
}
duk_ret_t js_DrawRect(duk_context *ctx) {
  auto x = duk_to_int(ctx, 0);
  auto y = duk_to_int(ctx, 1);
  auto w = duk_to_int(ctx, 2);
  auto h = duk_to_int(ctx, 3);
  auto color = GetColor(ctx, 4);

  DrawRect(GetGlobalContext(), x, y, w, h, color);
  return 0;
}
duk_ret_t js_DrawCircle(duk_context *ctx) {
  auto x = duk_to_int(ctx, 0);
  auto y = duk_to_int(ctx, 1);
  auto r = duk_to_int(ctx, 2);
  auto color = GetColor(ctx, 3);
  DrawCircle(GetGlobalContext(), x, y, r, color);
  return 0;
}
duk_ret_t js_DrawCircleFill(duk_context *ctx) {
  auto x = duk_to_int(ctx, 0);
  auto y = duk_to_int(ctx, 1);
  auto r = duk_to_int(ctx, 2);
  auto color = GetColor(ctx, 3);
  DrawCircleFill(GetGlobalContext(), x, y, r, color);
  return 0;
}
duk_ret_t js_DrawSprite(duk_context *ctx) {
  auto sprite_id = duk_to_int(ctx, 0);
  auto screen_x = duk_to_int(ctx, 1);
  auto screen_y = duk_to_int(ctx, 2);
  auto sheet_x = duk_to_int(ctx, 3);
  auto sheet_y = duk_to_int(ctx, 4);
  auto width = duk_to_int(ctx, 5);
  auto height = duk_to_int(ctx, 6);
  DrawSprite(GetGlobalContext(), sprite_id, screen_x, screen_y, sheet_x, sheet_y, width, height);
  return 0;
}