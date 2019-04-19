#include "js_lifecycle.h"
#include <whycpp/lifecycle.h>
#include "global_app_context.h"

duk_ret_t js_ExitApp(duk_context* ctx) {
  ExitApp(GetGlobalContext());
  return 0;
}
