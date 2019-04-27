#ifndef WHYCPP_ROOT_WHYCPP_JS_SRC_JS_STL_H_
#define WHYCPP_ROOT_WHYCPP_JS_SRC_JS_STL_H_

#include <whycpp_js/js_registrator.h>

class STLRegistrator: public JsRegistrator {
 public:
  void Register(duk_context* ctx) override;
};

#endif //WHYCPP_ROOT_WHYCPP_JS_SRC_JS_STL_H_
