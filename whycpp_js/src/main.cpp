#include <duktape.h>
#include <whycpp/application_config.h>
#include <whycpp/log.h>
#include <whycpp/whycpp.h>
#include "duk_helpers.h"
#include "js_application.h"
#include "js_stl.h"
#include "js_whycpp.h"

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

int main(int argc, char *argv[]) {
  SetLogLevel(LogLevel::DEBUG);

  duk_context *duk = duk_create_heap_default();
  duk_push_global_object(duk);
  SetupSTL(duk);
  SetupWhyCPP(duk);
  // TODO: to support web we should read file from a bytebuffer inserted directly into html page
  RunScript(duk, "main.js");
  auto config = GetConfig(duk);
  Run(new JsApplication(duk), config);
}