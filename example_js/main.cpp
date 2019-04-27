#include <whycpp/drawing.h>
#include <whycpp/log.h>
#include <whycpp/palette.h>
#include <whycpp/text.h>
#include <whycpp_js/get_global_context.h>
#include <whycpp_js/js_application_runner.h>
#include <whycpp_js/js_registrator.h>

static duk_ret_t native_hello_world(duk_context *ctx) {
  DrawClearScreen(GetGlobalContext(), PALETTE[0]);
  Print(GetGlobalContext(), 'H', 10, 10, PALETTE[2]);
  Print(GetGlobalContext(), 'H', 10, 20, PALETTE[2], 2);
  Print(GetGlobalContext(), "Hello World", 10, 40, PALETTE[3], 2);
  return 0;
}

class ExampleRegistrator: public JsRegistrator {
 public:
  void Register(duk_context* ctx) override {
    duk_push_c_function(ctx, native_hello_world, 0);
    duk_put_global_string(ctx, "native_hello_world");
  }
};

int main(int argc, char* argv[]) {
  SetLogLevel(LogLevel::DEBUG);

  char const* root_path;
  if (argc < 2) {
    root_path = "main.js";
  } else {
    root_path = argv[1];
  }

  JsApplicationRunner runner(root_path);
  runner.AddRegistrator(new ExampleRegistrator());
  runner.Execute();
}