#pragma once

#include <duktape.h>

class JsRegistrator {
 public:
  virtual void Register(duk_context *ctx) = 0;
  virtual ~JsRegistrator() = default;
};
