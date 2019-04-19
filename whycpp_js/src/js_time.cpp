#include <duktape.h>
#include <whycpp/time.h>
#include "global_app_context.h"
#include "js_time.h"

duk_ret_t js_GetTime(duk_context *ctx) {
  auto time = GetTime(GetGlobalContext());
  duk_push_number(ctx, time);
  return 1;
}

duk_ret_t js_GetDelta(duk_context *ctx) {
  auto time = GetDelta(GetGlobalContext());
  duk_push_number(ctx, time);
  return 1;
}