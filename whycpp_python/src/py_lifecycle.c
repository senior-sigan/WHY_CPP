#include "py_lifecycle.h"
#include <whycpp_c/lifecycle.h>

PyObject* py_ExitApp(PyObject* self, PyObject* args){
  ExitApp_C();
  Py_RETURN_NONE;
}
