#include "int_utils.h"

size_t AsSize(int value) {
  if (value < 0) return 0;
  return static_cast<size_t>(value);
}
