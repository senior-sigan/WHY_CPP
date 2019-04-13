#ifndef WHYCPP_ROOT_WHYCPP_JS_SRC_JS_APPLICATION_H_
#define WHYCPP_ROOT_WHYCPP_JS_SRC_JS_APPLICATION_H_

#include <duktape.h>
#include <whycpp/application_listener.h>

class JsApplication : public ApplicationListener {
  duk_context *duk;
  void CallFunc(const char *name);

 public:
  explicit JsApplication(duk_context *duk) : duk(duk) {}

  void OnCreate(Context &context) override;
  void OnDispose(Context &context) override;
  void OnPause(Context &context) override;
  void OnResume(Context &context) override;
  void OnRender(Context &context) override;

  ~JsApplication() override;
};

#endif  // WHYCPP_ROOT_WHYCPP_JS_SRC_JS_APPLICATION_H_
