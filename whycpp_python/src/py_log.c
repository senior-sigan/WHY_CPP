#include "py_log.h"
#include <whycpp_c/log.h>

PyObject* py_LogInfo(PyObject* self, PyObject* args){
  const char* str;
  PyArg_ParseTuple(args, "s", &str);
  LOG_INFO(str);
  Py_RETURN_NONE;
}
