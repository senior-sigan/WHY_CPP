#include "py_text.h"
#include <whycpp_c/text.h>
PyObject* py_PrintChar(PyObject* self, PyObject* args) {
  const char* ch;
  float x, y, size;
  uint32_t color_code;

  PyArg_ParseTuple(args, "sffIf", &ch, &x, &y, &color_code, &size);

  RGBA_t color;
  color.raw = color_code;
  PrintChar_C(ch[0], (int) x, (int) y, color, (int) size);

  Py_RETURN_NONE;
}
PyObject* py_PrintStr(PyObject* self, PyObject* args) {
  const char* ch;
  float x, y, size, spacing;
  uint32_t color_code;

  PyArg_ParseTuple(args, "sffIff", &ch, &x, &y, &color_code, &size, &spacing);

  RGBA_t color;
  color.raw = color_code;
  PrintStr_C(ch, (int) x, (int) y, color, (int) size, (int) spacing);

  Py_RETURN_NONE;
}
