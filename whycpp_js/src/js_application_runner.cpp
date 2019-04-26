#include <whycpp_js/js_application_runner.h>
#include <duktape.h>
#include <whycpp/whycpp.h>
#include "duk_helpers.h"
#include "js_application.h"
#include "js_config_reader.h"
#include "js_stl.h"
#include "js_whycpp.h"

JsApplicationRunner::JsApplicationRunner(const char *root_path) : root_path_(root_path) {}
void JsApplicationRunner::Execute() {
  duk_context *duk = duk_create_heap_default();
  duk_push_global_object(duk);
  SetupSTL(duk);
  SetupWhyCPP(duk);
  // TODO: to support web we should read file from a bytebuffer inserted directly into html page
  RunScript(duk, root_path_);
  auto config = GetConfig(duk);
  Run(new JsApplication(duk), config);
}
