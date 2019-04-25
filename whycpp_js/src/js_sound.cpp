#include "js_sound.h"
#include <whycpp/sound.h>
#include <string>
#include "duk_helpers.h"
#include "global_app_context.h"

duk_ret_t js_ImportMusic(duk_context* ctx) {
  auto path = duk_to_string(ctx, 0);
  auto name = duk_to_string(ctx, 1);
  ImportMusic(GetGlobalContext(), path, name);
  return 0;
}
duk_ret_t js_ImportSFX(duk_context* ctx) {
  auto path = duk_to_string(ctx, 0);
  auto name = duk_to_string(ctx, 1);
  ImportSFX(GetGlobalContext(), path, name);
  return 0;
}
duk_ret_t js_PlayMusic(duk_context* ctx) {
  auto name = duk_to_string(ctx, 0);
  auto loops = GetDukInt(ctx, 1, 0);
  PlayMusic(GetGlobalContext(), name, loops);
  return 0;
}
duk_ret_t js_PlaySFX(duk_context* ctx) {
  auto name = duk_to_string(ctx, 0);
  auto loops = GetDukInt(ctx, 1, 0);
  auto ticks = GetDukInt(ctx, 2, -1);
  PlaySFX(GetGlobalContext(), name, loops, ticks);
  return 0;
}
