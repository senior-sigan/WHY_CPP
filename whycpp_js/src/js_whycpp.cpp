#include "js_whycpp.h"
#include <whycpp/drawing.h>
#include <whycpp/log.h>
#include <whycpp/palette.h>
#include <iostream>
#include "global_app_context.h"

static duk_ret_t js_GetDisplayWidth(duk_context *ctx) {
  auto w = GetDisplayWidth(*GetGlobalContext());
  duk_push_number(ctx, w);
  return 1;
}
static duk_ret_t js_GetDisplayHeight(duk_context *ctx) {
  auto h = GetDisplayHeight(*GetGlobalContext());
  duk_push_number(ctx, h);
  return 1;
}
static duk_ret_t js_Palette(duk_context *ctx);
static duk_ret_t js_SetPixel(duk_context *ctx);
static duk_ret_t js_GetPixel(duk_context *ctx);
static duk_ret_t js_DrawClearScreen(duk_context *ctx);
static duk_ret_t js_DrawLine(duk_context *ctx);
static duk_ret_t js_DrawRectFill(duk_context *ctx) {
  RGBA color{};
  auto x = duk_to_int(ctx, 0);
  auto y = duk_to_int(ctx, 1);
  auto w = duk_to_int(ctx, 2);
  auto h = duk_to_int(ctx, 3);
  auto len = duk_get_length(ctx, 4);
  if (len != 4) {
    LOG_ERROR("Color should be array of 4 ints, but got %d", len);
  } else {
    duk_get_prop_index(ctx, 4, 0);
    color.red = duk_to_uint16(ctx, -1);
    duk_get_prop_index(ctx, 4, 1);
    color.green = duk_to_uint16(ctx, -1);
    duk_get_prop_index(ctx, 4, 2);
    color.blue = duk_to_uint16(ctx, -1);
    duk_get_prop_index(ctx, 4, 3);
    color.alpha = duk_to_uint16(ctx, -1);
  }

  DrawRectFill(*GetGlobalContext(), x, y, w, h, color);
  return 0;
}
static duk_ret_t js_DrawRect(duk_context *ctx);
static duk_ret_t js_DrawCircle(duk_context *ctx);
static duk_ret_t js_DrawCircleFill(duk_context *ctx);
static duk_ret_t js_DrawSprite(duk_context *ctx);

static const struct {
  duk_c_function func;
  int params;
  const char *name;
} ApiFunc[] = {{js_GetDisplayHeight, 0, "get_display_height"},
               {js_GetDisplayWidth, 0, "get_display_width"},
               {js_DrawRectFill, DUK_VARARGS, "draw_rect_fill"}};

static void SetupPaletteConst(duk_context *ctx) {
  auto pal_idx = duk_push_array(ctx);
  for (int i = 0; i < PALETTE_LEN; i++) {
    auto color = PALETTE[i];
    auto colors_idx = duk_push_array(ctx);
    duk_push_number(ctx, color.red);
    duk_put_prop_index(ctx, colors_idx, 0);
    duk_push_number(ctx, color.green);
    duk_put_prop_index(ctx, colors_idx, 1);
    duk_push_number(ctx, color.blue);
    duk_put_prop_index(ctx, colors_idx, 2);
    duk_push_number(ctx, color.alpha);
    duk_put_prop_index(ctx, colors_idx, 3);
    duk_put_prop_index(ctx, pal_idx, i);
  }
  duk_put_global_string(ctx, "PALETTE");
}

void SetupWhyCPP(duk_context *ctx) {
  for (const auto &i : ApiFunc) {
    duk_push_c_function(ctx, i.func, i.params);
    duk_put_global_string(ctx, i.name);
  }

  duk_push_number(ctx, PALETTE_LEN);
  duk_put_global_string(ctx, "PALETTE_LEN");

  SetupPaletteConst(ctx);
}