#ifndef WHYCPP_ROOTWHYCPP_PYTHON_SRC_DRAWING_WRAPPERS_H_
#define WHYCPP_ROOTWHYCPP_PYTHON_SRC_DRAWING_WRAPPERS_H_

#include <Python.h>

PyObject* py_GetDisplayWidth(PyObject* self, PyObject* args);
PyObject* py_GetDisplayHeight(PyObject* self, PyObject* args);
PyObject* py_Palette(PyObject* self, PyObject* args);
PyObject* py_NumAsRgba(PyObject* self, PyObject* args);
PyObject* py_RgbaAsNum(PyObject* self, PyObject* args);
PyObject* py_SetPixel(PyObject* self, PyObject* args);
PyObject* py_GetPixel(PyObject* self, PyObject* args);
PyObject* py_DrawClearScreen(PyObject* self, PyObject* args);
PyObject* py_DrawLine(PyObject* self, PyObject* args);
PyObject* py_DrawRectFill(PyObject* self, PyObject* args);
PyObject* py_DrawRect(PyObject* self, PyObject* args);
PyObject* py_DrawCircle(PyObject* self, PyObject* args);
PyObject* py_DrawCircleFill(PyObject* self, PyObject* args);
PyObject* py_DrawSprite(PyObject* self, PyObject* args);

#endif  // WHYCPP_ROOTWHYCPP_PYTHON_SRC_DRAWING_WRAPPERS_H_
