#include "int_utils.h"
#include <whycpp/types.h>

size_t AsSize(i32 value) {
  if (value < 0) return 0;
  return static_cast<size_t>(value);
}
