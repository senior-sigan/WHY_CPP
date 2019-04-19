#include <duktape.h>
#include <whycpp/text.h>
#include <string>
#include "color_helpers.h"
#include "duk_helpers.h"
#include "global_app_context.h"

duk_ret_t js_ShowText(duk_context *ctx) {
  std::string str = duk_to_string(ctx, 0);
  auto x = duk_to_int(ctx, 1);
  auto y = duk_to_int(ctx, 2);
  auto color = GetColor(ctx, 3);
  auto size = GetDukInt(ctx, 4, 1);
  auto spacing = GetDukInt(ctx, 5, 0);
  Print(GetGlobalContext(), str, x, y, color, size, spacing);
  return 0;
}