#ifndef WHYCPP_ROOT_WHYCPP_PYTHON_SRC_PY_INPUT_H_
#define WHYCPP_ROOT_WHYCPP_PYTHON_SRC_PY_INPUT_H_

#include <Python.h>

PyObject* py_IsPressed(PyObject* self, PyObject* args);
PyObject* py_IsClicked(PyObject* self, PyObject* args);
PyObject* py_GetMouse(PyObject* self, PyObject* args);

#endif  // WHYCPP_ROOT_WHYCPP_PYTHON_SRC_PY_INPUT_H_
