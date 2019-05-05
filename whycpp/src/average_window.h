#ifndef WHYCPP_ROOT_WHYCPP_SRC_AVERAGE_WINDOW_H_
#define WHYCPP_ROOT_WHYCPP_SRC_AVERAGE_WINDOW_H_

#include <vector>

template<typename T>
class AverageWindow {
  std::vector<T> history;
  size_t size_;
  size_t current = 0;
  T sum = 0;

 public:
  explicit AverageWindow(size_t size) : history(size, 0), size_(size) {}
  void Add(T value) {
    sum += value;
    sum -= history[current];
    history[current] = value;
    current = (current + 1) % size_;
  }
  T Get() const {
    return sum / size_;
  }
};

#endif  // WHYCPP_ROOT_WHYCPP_SRC_AVERAGE_WINDOW_H_
