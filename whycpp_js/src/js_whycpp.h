#pragma once

#include <whycpp_js/js_registrator.h>

class WhycppRegistrator : public JsRegistrator {
 public:
  void Register(duk_context* ctx) override;
};
