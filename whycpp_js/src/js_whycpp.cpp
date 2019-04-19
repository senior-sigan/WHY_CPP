#include "js_whycpp.h"
#include <whycpp/buttons.h>
#include <whycpp/drawing.h>
#include <whycpp/input.h>
#include <whycpp/log.h>
#include <whycpp/palette.h>
#include <whycpp/time.h>
#include <iostream>
#include "duk_helpers.h"
#include "global_app_context.h"

static duk_idx_t PutColor(duk_context *ctx, const RGBA &color) {
  auto colors_idx = duk_push_array(ctx);
  duk_push_number(ctx, color.red);
  duk_put_prop_index(ctx, colors_idx, 0);
  duk_push_number(ctx, color.green);
  duk_put_prop_index(ctx, colors_idx, 1);
  duk_push_number(ctx, color.blue);
  duk_put_prop_index(ctx, colors_idx, 2);
  duk_push_number(ctx, color.alpha);
  duk_put_prop_index(ctx, colors_idx, 3);
  return colors_idx;
}

static RGBA GetColor(duk_context *ctx, duk_idx_t idx) {
  RGBA color{};
  auto len = duk_get_length(ctx, idx);
  if (len != 4) {
    LOG_ERROR("Color should be array of 4 ints, but got %d", len);
  } else {
    duk_get_prop_index(ctx, idx, 0);
    color.red = duk_to_uint16(ctx, -1);
    duk_get_prop_index(ctx, idx, 1);
    color.green = duk_to_uint16(ctx, -1);
    duk_get_prop_index(ctx, idx, 2);
    color.blue = duk_to_uint16(ctx, -1);
    duk_get_prop_index(ctx, idx, 3);
    color.alpha = duk_to_uint16(ctx, -1);
  }
  return color;
}

static duk_ret_t js_GetDisplayWidth(duk_context *ctx) {
  auto w = GetDisplayWidth(GetGlobalContext());
  duk_push_number(ctx, w);
  return 1;
}
static duk_ret_t js_GetDisplayHeight(duk_context *ctx) {
  auto h = GetDisplayHeight(GetGlobalContext());
  duk_push_number(ctx, h);
  return 1;
}
static duk_ret_t js_SetPixel(duk_context *ctx) {
  auto x = duk_to_int(ctx, 0);
  auto y = duk_to_int(ctx, 1);
  auto color = GetColor(ctx, 2);
  SetPixel(GetGlobalContext(), x, y, color);
  return 0;
}
static duk_ret_t js_GetPixel(duk_context *ctx) {
  auto x = duk_to_int(ctx, 0);
  auto y = duk_to_int(ctx, 1);
  auto color = GetPixel(GetGlobalContext(), x, y);
  PutColor(ctx, color);
  return 1;
}
static duk_ret_t js_DrawClearScreen(duk_context *ctx) {
  auto color = GetColor(ctx, 0);
  DrawClearScreen(GetGlobalContext(), color);
  return 0;
}
static duk_ret_t js_DrawLine(duk_context *ctx) {
  auto x0 = duk_to_int(ctx, 0);
  auto y0 = duk_to_int(ctx, 1);
  auto x1 = duk_to_int(ctx, 2);
  auto y1 = duk_to_int(ctx, 3);
  auto color = GetColor(ctx, 4);
  DrawLine(GetGlobalContext(), x0, y0, x1, y1, color);
  return 0;
}
static duk_ret_t js_DrawRectFill(duk_context *ctx) {
  auto x = duk_to_int(ctx, 0);
  auto y = duk_to_int(ctx, 1);
  auto w = duk_to_int(ctx, 2);
  auto h = duk_to_int(ctx, 3);
  auto color = GetColor(ctx, 4);

  DrawRectFill(GetGlobalContext(), x, y, w, h, color);
  return 0;
}
static duk_ret_t js_DrawRect(duk_context *ctx) {
  auto x = duk_to_int(ctx, 0);
  auto y = duk_to_int(ctx, 1);
  auto w = duk_to_int(ctx, 2);
  auto h = duk_to_int(ctx, 3);
  auto color = GetColor(ctx, 4);

  DrawRect(GetGlobalContext(), x, y, w, h, color);
  return 0;
}
static duk_ret_t js_DrawCircle(duk_context *ctx) {
  auto x = duk_to_int(ctx, 0);
  auto y = duk_to_int(ctx, 1);
  auto r = duk_to_int(ctx, 2);
  auto color = GetColor(ctx, 3);
  DrawCircle(GetGlobalContext(), x, y, r, color);
  return 0;
}
static duk_ret_t js_DrawCircleFill(duk_context *ctx) {
  auto x = duk_to_int(ctx, 0);
  auto y = duk_to_int(ctx, 1);
  auto r = duk_to_int(ctx, 2);
  auto color = GetColor(ctx, 3);
  DrawCircle(GetGlobalContext(), x, y, r, color);
  return 0;
}
static duk_ret_t js_DrawSprite(duk_context *ctx) {
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

static duk_ret_t js_GetTime(duk_context *ctx) {
  auto time = GetTime(GetGlobalContext());
  duk_push_number(ctx, time);
  return 1;
}

static duk_ret_t js_GetDelta(duk_context *ctx) {
  auto time = GetDelta(GetGlobalContext());
  duk_push_number(ctx, time);
  return 1;
}

static duk_ret_t js_IsClicked(duk_context *ctx) {
  auto btn = duk_to_int(ctx, 0);
  auto clk = IsClicked(GetGlobalContext(), static_cast<const Button>(btn));
  duk_push_boolean(ctx, clk);
  return 1;
}

static duk_ret_t js_IsPressed(duk_context *ctx) {
  auto btn = duk_to_int(ctx, 0);
  auto clk = IsPressed(GetGlobalContext(), static_cast<const Button>(btn));
  duk_push_boolean(ctx, clk);
  return 1;
}

static const struct {
  duk_c_function func;
  int params;
  const char *name;
} ApiFunc[] = {{js_GetDisplayHeight, 0, "get_display_height"},
               {js_GetDisplayWidth, 0, "get_display_width"},
               {js_DrawRectFill, DUK_VARARGS, "draw_rect_fill"},
               {js_DrawRect, DUK_VARARGS, "draw_rect"},
               {js_GetPixel, 2, "get_pixel"},
               {js_SetPixel, 3, "set_pixel"},
               {js_DrawClearScreen, 1, "draw_clear_screen"},
               {js_DrawLine, 5, "draw_line"},
               {js_DrawCircle, 4, "draw_circle"},
               {js_DrawCircleFill, 4, "draw_circle_fill"},
               {js_DrawSprite, 7, "draw_sprite"},
               {js_GetTime, 0, "get_time"},
               {js_GetDelta, 0, "get_delta"},
               {js_IsClicked, 1, "is_clicked"},
               {js_IsPressed, 1, "is_pressed"}
};

static void SetupPaletteConst(duk_context *ctx) {
  auto pal_idx = duk_push_array(ctx);
  for (int i = 0; i < PALETTE_LEN; i++) {
    auto color = PALETTE[i];
    PutColor(ctx, color);
    duk_put_prop_index(ctx, pal_idx, i);
  }
  duk_put_global_string(ctx, "PALETTE");
}

static void RegisterButtons(duk_context *ctx) {
  RegisterConstant(ctx, "KEY_A", KEY_A);
  RegisterConstant(ctx, "KEY_B", KEY_B);
  RegisterConstant(ctx, "KEY_C", KEY_C);
  RegisterConstant(ctx, "KEY_D", KEY_D);
  RegisterConstant(ctx, "KEY_E", KEY_E);
  RegisterConstant(ctx, "KEY_F", KEY_F);
  RegisterConstant(ctx, "KEY_G", KEY_G);
  RegisterConstant(ctx, "KEY_H", KEY_H);
  RegisterConstant(ctx, "KEY_I", KEY_I);
  RegisterConstant(ctx, "KEY_J", KEY_J);
  RegisterConstant(ctx, "KEY_K", KEY_K);
  RegisterConstant(ctx, "KEY_L", KEY_L);
  RegisterConstant(ctx, "KEY_M", KEY_M);
  RegisterConstant(ctx, "KEY_N", KEY_N);
  RegisterConstant(ctx, "KEY_O", KEY_O);
  RegisterConstant(ctx, "KEY_P", KEY_P);
  RegisterConstant(ctx, "KEY_Q", KEY_Q);
  RegisterConstant(ctx, "KEY_R", KEY_R);
  RegisterConstant(ctx, "KEY_S", KEY_S);
  RegisterConstant(ctx, "KEY_T", KEY_T);
  RegisterConstant(ctx, "KEY_U", KEY_U);
  RegisterConstant(ctx, "KEY_V", KEY_V);
  RegisterConstant(ctx, "KEY_W", KEY_W);
  RegisterConstant(ctx, "KEY_X", KEY_X);
  RegisterConstant(ctx, "KEY_Y", KEY_Y);
  RegisterConstant(ctx, "KEY_Z", KEY_Z);
  RegisterConstant(ctx, "KEY_1", KEY_1);
  RegisterConstant(ctx, "KEY_2", KEY_2);
  RegisterConstant(ctx, "KEY_3", KEY_3);
  RegisterConstant(ctx, "KEY_4", KEY_4);
  RegisterConstant(ctx, "KEY_5", KEY_5);
  RegisterConstant(ctx, "KEY_6", KEY_6);
  RegisterConstant(ctx, "KEY_7", KEY_7);
  RegisterConstant(ctx, "KEY_8", KEY_8);
  RegisterConstant(ctx, "KEY_9", KEY_9);
  RegisterConstant(ctx, "KEY_0", KEY_0);
  RegisterConstant(ctx, "KEY_RETURN", KEY_RETURN);
  RegisterConstant(ctx, "KEY_ESCAPE", KEY_ESCAPE);
  RegisterConstant(ctx, "KEY_BACKSPACE", KEY_BACKSPACE);
  RegisterConstant(ctx, "KEY_TAB", KEY_TAB);
  RegisterConstant(ctx, "KEY_SPACE", KEY_SPACE);
  RegisterConstant(ctx, "KEY_F1", KEY_F1);
  RegisterConstant(ctx, "KEY_F2", KEY_F2);
  RegisterConstant(ctx, "KEY_F3", KEY_F3);
  RegisterConstant(ctx, "KEY_F4", KEY_F4);
  RegisterConstant(ctx, "KEY_F5", KEY_F5);
  RegisterConstant(ctx, "KEY_F6", KEY_F6);
  RegisterConstant(ctx, "KEY_F7", KEY_F7);
  RegisterConstant(ctx, "KEY_F8", KEY_F8);
  RegisterConstant(ctx, "KEY_F9", KEY_F9);
  RegisterConstant(ctx, "KEY_F10", KEY_F10);
  RegisterConstant(ctx, "KEY_F11", KEY_F11);
  RegisterConstant(ctx, "KEY_F12", KEY_F12);
  RegisterConstant(ctx, "KEY_RIGHT", KEY_RIGHT);
  RegisterConstant(ctx, "KEY_LEFT", KEY_LEFT);
  RegisterConstant(ctx, "KEY_DOWN", KEY_DOWN);
  RegisterConstant(ctx, "KEY_UP", KEY_UP);
  RegisterConstant(ctx, "KEY_LCTRL", KEY_LCTRL);
  RegisterConstant(ctx, "KEY_LSHIFT", KEY_LSHIFT);
  RegisterConstant(ctx, "KEY_LALT", KEY_LALT);
  RegisterConstant(ctx, "KEY_RCTRL", KEY_RCTRL);
  RegisterConstant(ctx, "KEY_RSHIFT", KEY_RSHIFT);
  RegisterConstant(ctx, "KEY_RALT", KEY_RALT);
  RegisterConstant(ctx, "MOUSE_BUTTON_LEFT", MOUSE_BUTTON_LEFT);
  RegisterConstant(ctx, "MOUSE_BUTTON_MIDDLE", MOUSE_BUTTON_MIDDLE);
  RegisterConstant(ctx, "MOUSE_BUTTON_RIGHT", MOUSE_BUTTON_RIGHT);
}

void SetupWhyCPP(duk_context *ctx) {
  for (const auto &i : ApiFunc) {
    duk_push_c_function(ctx, i.func, i.params);
    duk_put_global_string(ctx, i.name);
  }

  RegisterConstant(ctx, "PALETTE_LEN", PALETTE_LEN);
  RegisterButtons(ctx);

  SetupPaletteConst(ctx);
}