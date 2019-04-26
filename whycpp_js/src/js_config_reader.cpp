#include "js_config_reader.h"
#include <duktape.h>
#include "duk_helpers.h"

ApplicationConfig GetConfig(duk_context *ctx) {
  duk_get_prop_string(ctx, -1, "CONFIG");
  duk_get_prop_string(ctx, -1, "width");
  duk_get_prop_string(ctx, -2, "height");
  duk_get_prop_string(ctx, -3, "name");
  duk_get_prop_string(ctx, -4, "is_fullscreen");
  duk_get_prop_string(ctx, -5, "window_size_multiplier");
  duk_get_prop_string(ctx, -6, "ms_per_frame");
  int width = GetDukInt(ctx, -6, 256);
  int height = GetDukInt(ctx, -5, 144);
  std::string name = GetDukStr(ctx, -4, "JS App");
  bool is_fullscreen = GetDukBool(ctx, -3, false);
  int window_size_multiplier = GetDukInt(ctx, -2, 3);
  int ms_per_frame = GetDukInt(ctx, -1, 16);
  duk_pop_n(ctx, 7);

  return ApplicationConfig(width, height, name, is_fullscreen, window_size_multiplier, ms_per_frame);
}
