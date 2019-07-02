#pragma once

#include <stdint.h>

struct RGBA_t_ {
  uint8_t red;
  uint8_t green;
  uint8_t blue;
  uint8_t alpha;
};

typedef union {
  uint32_t raw;
  struct RGBA_t_ rgba;
} RGBA_t;
