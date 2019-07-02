#pragma once

#include <whycpp/color.h>
#include <whycpp_c/color.h>

typedef union {
  struct RGBA rgba;
  uint32_t raw;
} RGBA_conv;

RGBA_t to_C(const RGBA &color);

RGBA to_Cpp(RGBA_t color);
