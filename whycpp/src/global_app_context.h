#ifndef WHYCPP_ROOT_WHYCPP_JS_SRC_GLOBAL_APP_CONTEXT_H_
#define WHYCPP_ROOT_WHYCPP_JS_SRC_GLOBAL_APP_CONTEXT_H_

#include "context.h"

Context& GetContext();
Context* GetContextPtr();
void SetContext(Context* ctx);

#endif  // WHYCPP_ROOT_WHYCPP_JS_SRC_GLOBAL_APP_CONTEXT_H_
