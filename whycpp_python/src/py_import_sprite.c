#include "py_import_sprite.h"
#include <whycpp_c/import_sprites.h>

PyObject* py_ImportSprite(PyObject* self, PyObject* args) {
  const char* file_name;
  PyArg_ParseTuple(args, "s", &file_name);
  int id = ImportSprite_C(file_name);
  return PyLong_FromLong(id);
}
