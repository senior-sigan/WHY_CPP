#include "py_drawing.h"
#include <whycpp/log.h>
#include <whycpp_c/drawing.h>
#include <whycpp_c/palette.h>

PyObject* py_GetDisplayWidth(PyObject* self, PyObject* args) {
  int width = GetDisplayWidth_C();
  return PyLong_FromLong(width);
}
PyObject* py_GetDisplayHeight(PyObject* self, PyObject* args) {
  int height = GetDisplayHeight_C();
  return PyLong_FromLong(height);
}
PyObject* py_Palette(PyObject* self, PyObject* args) {
  int i;
  PyArg_ParseTuple(args, "I", &i);
  if (i >= PALETTE_LEN) {
    LOG_WARN("PALETTE_LEN could not be > %d, but %d", PALETTE_LEN, i);
    return PyLong_FromLong(PALETTE[0].raw);
  }
  return PyLong_FromLong(PALETTE[i].raw);
}
PyObject* py_NumAsRgba(PyObject* self, PyObject* args) {
  uint32_t color;
  PyArg_ParseTuple(args, "I", &color);
  RGBA_t rgba;
  rgba.raw = color;
  PyObject* tuple = PyTuple_New(4);
  PyTuple_SetItem(tuple, 0, PyLong_FromLong(rgba.rgba.red));
  PyTuple_SetItem(tuple, 1, PyLong_FromLong(rgba.rgba.green));
  PyTuple_SetItem(tuple, 2, PyLong_FromLong(rgba.rgba.blue));
  PyTuple_SetItem(tuple, 3, PyLong_FromLong(rgba.rgba.alpha));

  return tuple;
}
PyObject* py_RgbaAsNum(PyObject* self, PyObject* args) {
  uint8_t red;
  uint8_t green;
  uint8_t blue;
  uint8_t alpha;
  PyArg_ParseTuple(args, "IIII", &red, &green, &blue, &alpha);
  struct RGBA_t_ rgba = {red, green, blue, alpha};
  RGBA_t conv;
  conv.rgba = rgba;

  return PyLong_FromLong(conv.raw);
}
PyObject* py_SetPixel(PyObject* self, PyObject* args) {
  float x;
  float y;
  uint32_t color;
  PyArg_ParseTuple(args, "ffI", &x, &y, &color);
  RGBA_t rgba;
  rgba.raw = color;
  SetPixel_C((int) x, (int) y, rgba);
  Py_RETURN_NONE;
}
PyObject* py_GetPixel(PyObject* self, PyObject* args) {
  float x;
  float y;
  PyArg_ParseTuple(args, "ff", &x, &y);
  RGBA_t color = GetPixel_C((int) x, (int) y);
  return PyLong_FromLong(color.raw);
}
PyObject* py_DrawClearScreen(PyObject* self, PyObject* args) {
  uint32_t color = 0;
  PyArg_ParseTuple(args, "|I", &color);
  RGBA_t rgba;
  rgba.raw = color;
  DrawClearScreen_C(rgba);
  Py_RETURN_NONE;
}
PyObject* py_DrawLine(PyObject* self, PyObject* args) {
  float x0, y0, x1, y1;
  uint32_t color_code;
  PyArg_ParseTuple(args, "ffffI", &x0, &y0, &x1, &y1, &color_code);
  RGBA_t color;
  color.raw = color_code;
  DrawLine_C((int) x0, (int) y0, (int) x1, (int) y1, color);
  Py_RETURN_NONE;
}
PyObject* py_DrawRectFill(PyObject* self, PyObject* args) {
  float x, y, w, h;
  uint32_t color_code;
  PyArg_ParseTuple(args, "ffffI", &x, &y, &w, &h, &color_code);
  RGBA_t color;
  color.raw = color_code;
  DrawRectFill_C((int) x, (int) y, (int) w, (int) h, color);
  Py_RETURN_NONE;
}
PyObject* py_DrawRect(PyObject* self, PyObject* args) {
  float x, y, w, h;
  uint32_t color_code;
  PyArg_ParseTuple(args, "ffffI", &x, &y, &w, &h, &color_code);
  RGBA_t color;
  color.raw = color_code;
  DrawRect_C((int) x, (int) y, (int) w, (int) h, color);
  Py_RETURN_NONE;
}
PyObject* py_DrawCircle(PyObject* self, PyObject* args) {
  float x, y, radius;
  uint32_t color_code;
  PyArg_ParseTuple(args, "fffI", &x, &y, &radius, &color_code);
  RGBA_t color;
  color.raw = color_code;
  DrawCircle_C((int) x, (int) y, (int) radius, color);
  Py_RETURN_NONE;
}
PyObject* py_DrawCircleFill(PyObject* self, PyObject* args) {
  float x, y, radius;
  uint32_t color_code;
  PyArg_ParseTuple(args, "fffI", &x, &y, &radius, &color_code);
  RGBA_t color;
  color.raw = color_code;
  DrawCircleFill_C((int) x, (int) y, (int) radius, color);
  Py_RETURN_NONE;
}
PyObject* py_DrawSprite(PyObject* self, PyObject* args) {
  int sprite_id;
  float screen_x, screen_y, sheet_x, sheet_y, width, height;
  PyArg_ParseTuple(args, "iffffff", &sprite_id, &screen_x, &screen_y, &sheet_x, &sheet_y, &width, &height);
  DrawSprite_C(sprite_id, (int) screen_x, (int) screen_y, (int) sheet_x, (int) sheet_y, (int) width, (int) height);
  Py_RETURN_NONE;
}
