#ifndef WHYCPP_CLAMP_H
#define WHYCPP_CLAMP_H

template<class T>
const T& clamp(const T& v, const T& lo, const T& hi) {
  if (v < lo) return lo;
  if (v > hi) return hi;
  return v;
}

#endif  // WHYCPP_CLAMP_H
