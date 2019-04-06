#include <stdio.h>
#include <stdlib.h>
#include <whycpp/log.h>
#include <whycpp_c/application_config.h>
#include <whycpp_c/application_listener.h>
#include <whycpp_c/whycpp_c.h>
#include "app_listener_py_wrappers.h"
#include "whycpp_wrapper.h"

void RunWhycpp(void) {
  ApplicationConfig_t config = {.width = 256,
                                .height = 144,
                                .name = "WhycppPy game",
                                .is_fullscreen = 0,
                                .window_size_multiplier = 3,
                                .ms_per_frame = 16};

  ApplicationListener_t listener = {
      .onCreate = OnCreate, .onResume = OnResume, .onRender = OnRender, .onPause = OnPause, .onDispose = OnDispose};

  SetLogLevel(INFO);
  Run(&listener, &config);
}

int main(int argc, char* argv[]) {
  if (argc < 2) {
    fprintf(stderr, "Usage: python dir_path\n");
    return 1;
  }

  char* name = "main";

  PyImport_AppendInittab("whycpp", &PyInit_whycpp);

  Py_Initialize();
  char* code = malloc(sizeof(char) * (33 + strlen(argv[1])));
  sprintf(code, "import sys\nsys.path.insert(0, \"%s\")", argv[1]);
  PyRun_SimpleString(code);

  PyObject* pName = PyUnicode_DecodeFSDefault(name);
  PyObject* pModule = PyImport_Import(pName);
  Py_DECREF(pName);

  RegisterWrappers(pModule);

  // TODO: get application config from the python

  RunWhycpp();

  UnregisterWrappers();
  Py_DECREF(pModule);

  Py_Finalize();
  return 0;
}