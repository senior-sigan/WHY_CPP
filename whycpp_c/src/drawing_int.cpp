#include "internal/drawing_int.h"
#include <whycpp_c/drawing.h>

RGBA_t to_C(const RGBA &color) {
  RGBA_conv conv;
  RGBA_t result;
  conv.rgba = color;
  result.raw = conv.raw;
  return result;
}

RGBA to_Cpp(RGBA_t color) {
  RGBA_conv conv;
  conv.raw = color.raw;
  return conv.rgba;
}
