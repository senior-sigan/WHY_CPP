#include "global_app_context.h"
#include <whycpp/log.h>

static Context* GLOBAL_CONTEXT = nullptr;

Context* GetGlobalContext() {
  if (GLOBAL_CONTEXT == nullptr) {
    LOG_CRITICAL("Context is requested before it was set!");
    return nullptr;
  }
  return GLOBAL_CONTEXT;
}

void SetGlobalContext(Context* ctx) {
  GLOBAL_CONTEXT = ctx;
}