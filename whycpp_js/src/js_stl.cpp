#include "js_stl.h"
#include <duk_module_node.h>
#include <whycpp/log.h>
#include "duk_helpers.h"

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

static duk_ret_t cb_resolve_module(duk_context *ctx) {
  const char *module_id;
  const char *parent_id;

  module_id = duk_require_string(ctx, 0);
  parent_id = duk_require_string(ctx, 1);

  duk_push_sprintf(ctx, "%s.js", module_id);
  printf("resolve_cb: id:'%s', parent-id:'%s', resolve-to:'%s'\n",
         module_id, parent_id, duk_get_string(ctx, -1));

  return 1;
}

static duk_ret_t cb_load_module(duk_context *ctx) {
  const char *filename;
  const char *module_id;

  module_id = duk_require_string(ctx, 0);
  duk_get_prop_string(ctx, 2, "filename");
  filename = duk_require_string(ctx, -1);

  printf("load_cb: id:'%s', filename:'%s'\n", module_id, filename);

  PushFileAsString(ctx, module_id);

  return 1;
}

void SetupSTL(duk_context *ctx) {
  for (const auto &i : ApiFunc) {
    duk_push_c_function(ctx, i.func, i.params);
    duk_put_global_string(ctx, i.name);
  }

  duk_push_object(ctx);
  duk_push_c_function(ctx, cb_resolve_module, DUK_VARARGS);
  duk_put_prop_string(ctx, -2, "resolve");
  duk_push_c_function(ctx, cb_load_module, DUK_VARARGS);
  duk_put_prop_string(ctx, -2, "load");
  duk_module_node_init(ctx);
}
