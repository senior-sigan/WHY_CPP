#include <whycpp/log.h>
#include <cstdio>
#include <cstdlib>
#include "internal/global_context_int.h"

Context* GLOBAL_CONTEXT = nullptr;

Context* GetContextInit() {
  LOG_CRITICAL("Context is requested before it was set!");
  return nullptr;
}

Context* GetContextNormal() {
  return GLOBAL_CONTEXT;
}

Context* (*get_context_internal)() = GetContextInit;

Context* GetContext_C() {
  return get_context_internal();
}

void SetContext_C(Context* context) {
  if (GLOBAL_CONTEXT != nullptr) {
    LOG_WARN("Redefinition of the context!");
  }
  GLOBAL_CONTEXT = context;
  get_context_internal = GetContextNormal;
}
