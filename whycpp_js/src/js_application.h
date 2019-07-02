#pragma once

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
