#include "js_application.h"
#include <whycpp/log.h>
#include "global_app_context.h"

void JsApplication::CallFunc(const char* name) {
  duk_get_prop_string(duk, -1, name);
  if (duk_pcall(duk, 0) != 0) {
    LOG_ERROR("%s: %s\n", name, duk_safe_to_string(duk, -1));
  }
  duk_pop(duk);
}
void JsApplication::OnCreate(Context& context) {
  SetGlobalContext(&context);
  CallFunc("onCreate");
}
void JsApplication::OnDispose(Context& context) {
  CallFunc("onDispose");
  SetGlobalContext(nullptr);
}
void JsApplication::OnPause(Context& context) {
  CallFunc("onPause");
}
void JsApplication::OnResume(Context& context) {
  CallFunc("onResume");
}
void JsApplication::OnRender(Context& context) {
  CallFunc("onRender");
}
JsApplication::~JsApplication(){
  duk_destroy_heap(duk);
}
