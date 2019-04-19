#ifndef WHYCPP_ROOT_WHYCPP_JS_SRC_GLOBAL_APP_CONTEXT_H_
#define WHYCPP_ROOT_WHYCPP_JS_SRC_GLOBAL_APP_CONTEXT_H_

class Context;

Context& GetGlobalContext();
Context* GetGlobalContextPtr();
void SetGlobalContext(Context* ctx);

#endif  // WHYCPP_ROOT_WHYCPP_JS_SRC_GLOBAL_APP_CONTEXT_H_
