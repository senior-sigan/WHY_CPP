#include <duktape.h>
#include <whycpp/buttons.h>
#include <whycpp/input.h>
#include "duk_helpers.h"
#include "global_app_context.h"

duk_ret_t js_IsClicked(duk_context *ctx) {
  auto btn = duk_to_int(ctx, 0);
  auto clk = IsClicked(GetGlobalContext(), static_cast<const Button>(btn));
  duk_push_boolean(ctx, clk);
  return 1;
}

duk_ret_t js_IsPressed(duk_context *ctx) {
  auto btn = duk_to_int(ctx, 0);
  auto clk = IsPressed(GetGlobalContext(), static_cast<const Button>(btn));
  duk_push_boolean(ctx, clk);
  return 1;
}

duk_ret_t js_GetMouse(duk_context *ctx) {
  int x, y;
  GetMouse(GetGlobalContext(), x, y);
  auto idx = duk_push_object(ctx);
  duk_push_number(ctx, x);
  duk_put_prop_string(ctx, idx, "x");
  duk_push_number(ctx, y);
  duk_put_prop_string(ctx, idx, "y");
  return 1;
}

void RegisterButtons(duk_context *ctx) {
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