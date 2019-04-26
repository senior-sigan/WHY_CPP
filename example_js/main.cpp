#include <whycpp/log.h>
#include <whycpp_js/js_application_runner.h>

int main(int argc, char* argv[]) {
  SetLogLevel(LogLevel::DEBUG);

  char const* root_path;
  if (argc < 2) {
    root_path = "main.js";
  } else {
    root_path = argv[1];
  }

  JsApplicationRunner runner(root_path);
  runner.Execute();
}