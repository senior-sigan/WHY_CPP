#include "global_app_context.h"
#include <whycpp/application_config.h>
#include <whycpp/log.h>

static Context* GLOBAL_CONTEXT = nullptr;

Context& GetContext() {
  return *GetContextPtr();
}

Context* GetContextPtr() {
  if (GLOBAL_CONTEXT == nullptr) {
    LOG_CRITICAL("Context is requested before it was set!");
    return nullptr;
  }
  return GLOBAL_CONTEXT;
}

void SetContext(Context* ctx) {
  GLOBAL_CONTEXT = ctx;
}
