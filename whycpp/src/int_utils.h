#pragma once

#include <whycpp/types.h>
#include <cstddef>

template<class T>
inline const T& clamp(const T& v, const T& lo, const T& hi) {
  if (v < lo) return lo;
  if (v > hi) return hi;
  return v;
}

size_t AsSize(i32 value);
