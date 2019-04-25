#include <duktape.h>
#include <whycpp/palette.h>
#include "color_helpers.h"
#include "duk_helpers.h"
#include "js_drawing.h"
#include "js_input.h"
#include "js_lifecycle.h"
#include "js_sound.h"
#include "js_text.h"
#include "js_time.h"

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
               {js_IsPressed, 1, "is_pressed"},
               {js_GetMouse, 0, "get_mouse"},
               {js_ShowText, DUK_VARARGS, "show_text"},
               {js_ExitApp, 0, "exit"},
               {js_ImportMusic, 2, "importMusic"},
               {js_ImportSFX, 2, "importSFX"},
               {js_PlayMusic, 2, "playMusic"},
               {js_PlaySFX, 3, "playSFX"}};

void SetupPaletteConst(duk_context *ctx) {
  RegisterConstant(ctx, "PALETTE_LEN", PALETTE_LEN);

  auto pal_idx = duk_push_array(ctx);
  for (int i = 0; i < PALETTE_LEN; i++) {
    auto color = PALETTE[i];
    PutColor(ctx, color);
    duk_put_prop_index(ctx, pal_idx, i);
  }
  duk_put_global_string(ctx, "PALETTE");
}

void SetupWhyCPP(duk_context *ctx) {
  for (const auto &i : ApiFunc) {
    duk_push_c_function(ctx, i.func, i.params);
    duk_put_global_string(ctx, i.name);
  }

  RegisterButtons(ctx);
  SetupPaletteConst(ctx);
}