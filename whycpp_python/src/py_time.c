#include "py_time.h"
#include <whycpp_c/time.h>

PyObject* py_GetTime(PyObject* self, PyObject* args){
  return PyFloat_FromDouble(GetTime_C());
}

PyObject* py_GetDelta(PyObject* self, PyObject* args){
  return PyFloat_FromDouble(GetDelta_C());
}
