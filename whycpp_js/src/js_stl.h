#pragma once

#include <whycpp_js/js_registrator.h>

class STLRegistrator: public JsRegistrator {
 public:
  void Register(duk_context* ctx) override;
};
