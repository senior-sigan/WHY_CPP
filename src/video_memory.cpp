#include "video_memory.h"
#include <whycpp/color.h>
#include <iostream>
#include <algorithm>
#include "clamp.h"

VideoMemory::VideoMemory(int width, int height) : width(width), height(height),
                                                  texture(std::vector<std::vector<RGBA>>(
                                                      static_cast<unsigned long>(width),
                                                      std::vector<RGBA>(static_cast<unsigned long>(height),
                                                                        {0, 0, 0, 0}))) {}
VideoMemory::~VideoMemory() = default;
void VideoMemory::Set(int x, int y, const RGBA &color) {
  texture.at(CheckX(x)).at(CheckY(y)) = color;
}
const RGBA &VideoMemory::Get(int x, int y) const {
  return texture.at(static_cast<unsigned long>(CheckX(x))).at(static_cast<unsigned long>(CheckY(y)));
}
int VideoMemory::GetHeight() const {
  return height;
}
int VideoMemory::GetWidth() const {
  return width;
}
size_t VideoMemory::CheckX(int x) const {
  if (x >= width || x < 0) {
    // TODO: use logger with macros to disable logs
    std::cout << "[WARN][VideoMemory]: X is out of bound, should be [0, " << width << "), but " << x << std::endl;
    return static_cast<size_t>(clamp(x, 0, width - 1));
  }
  return static_cast<size_t>(x);
}
size_t VideoMemory::CheckY(int y) const {
  if (y >= height || y < 0) {
    // TODO: use logger with macros to disable logs
    std::cout << "[WARN][VideoMemory]: Y is out of bound, should be [0, " << height << "), but " << y << std::endl;
    return static_cast<size_t>(clamp(y, 0, height - 1));
  }
  return static_cast<size_t>(y);
}
