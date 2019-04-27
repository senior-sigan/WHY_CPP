#ifndef WHYCPP_ROOT_WHYCPP_JS_SRC_JS_REGISTRATOR_H_
#define WHYCPP_ROOT_WHYCPP_JS_SRC_JS_REGISTRATOR_H_

#include <duktape.h>

class JsRegistrator {
 public:
  virtual void Register(duk_context *ctx) = 0;
  virtual ~JsRegistrator() = default;
};

#endif  // WHYCPP_ROOT_WHYCPP_JS_SRC_JS_REGISTRATOR_H_
