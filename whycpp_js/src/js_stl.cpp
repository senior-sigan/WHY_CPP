#include "js_stl.h"
#include <whycpp/log.h>

static duk_ret_t native_print(duk_context *ctx) {
  duk_push_string(ctx, " ");
  duk_insert(ctx, 0);
  duk_join(ctx, duk_get_top(ctx) - 1);
  LOG_INFO("%s\n", duk_safe_to_string(ctx, -1));
  return 0;
}

static const struct {
  duk_c_function func;
  int params;
  const char *name;
} ApiFunc[] = {{native_print, DUK_VARARGS, "print"}};

void SetupSTL(duk_context *ctx) {
  for (const auto &i : ApiFunc) {
    duk_push_c_function(ctx, i.func, i.params);
    duk_put_global_string(ctx, i.name);
  }
}
