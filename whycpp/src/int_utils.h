#ifndef WHYCPP_ROOT_WHYCPP_SRC_INT_UTILS_H_
#define WHYCPP_ROOT_WHYCPP_SRC_INT_UTILS_H_

#include <cstddef>
template<class T>
inline const T& clamp(const T& v, const T& lo, const T& hi) {
  if (v < lo) return lo;
  if (v > hi) return hi;
  return v;
}

size_t AsSize(int value);


#endif //WHYCPP_ROOT_WHYCPP_SRC_INT_UTILS_H_
