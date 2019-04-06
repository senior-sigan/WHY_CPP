#include "py_input.h"
#include <whycpp_c/input.h>
#include <whycpp_c/buttons.h>

PyObject* py_IsPressed(PyObject* self, PyObject* args) {
  Button_t btn;
  PyArg_ParseTuple(args, "i", &btn);
  if(IsPressed_C(btn)) {
    Py_RETURN_TRUE;
  } else {
    Py_RETURN_FALSE;
  }
}
PyObject* py_IsClicked(PyObject* self, PyObject* args) {
  Button_t btn;
  PyArg_ParseTuple(args, "i", &btn);
  if(IsClicked_C(btn)) {
    Py_RETURN_TRUE;
  } else {
    Py_RETURN_FALSE;
  }
}
PyObject* py_GetMouse(PyObject* self, PyObject* args) {
  int x, y;
  GetMouse_C(&x, &y);
  PyObject* tuple = PyTuple_New(2);
  PyTuple_SetItem(tuple, 0, PyLong_FromLong(x));
  PyTuple_SetItem(tuple, 1, PyLong_FromLong(y));
  return tuple;
}
