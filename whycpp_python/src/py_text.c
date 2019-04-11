#include "py_text.h"
#include <whycpp_c/text.h>
PyObject* py_PrintStr(PyObject* self, PyObject* args) {
  const char* ch;
  float x, y, size = 1, spacing = 0;
  uint32_t color_code;

  PyArg_ParseTuple(args, "sffI|ff", &ch, &x, &y, &color_code, &size, &spacing);

  RGBA_t color;
  color.raw = color_code;
  PrintStr_C(ch, (int) x, (int) y, color, (int) size, (int) spacing);

  Py_RETURN_NONE;
}
