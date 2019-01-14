#include "video_memory.h"
#include <whycpp/color.h>
#include <iostream>

VideoMemory::VideoMemory(int width, int height) : width(width), height(height) {
  texture = new RGBA *[width];
  for (int i = 0; i < width; i++) {
    texture[i] = new RGBA[height];
    for (int j = 0; j < height; j++) {
      texture[i][j] = {0, 0, 0, 0};
    }
  }
}
VideoMemory::~VideoMemory() {
  for (int i = 0; i < width; i++) {
    delete[] texture[i];
  }
  delete[] texture;
}
void VideoMemory::Set(int x, int y, const RGBA &color) {
  texture[CheckX(x)][CheckY(y)] = color;
}
const RGBA &VideoMemory::Get(int x, int y) const {
  return texture[CheckX(x)][CheckY(y)];
}
int VideoMemory::GetHeight() const {
  return height;
}
int VideoMemory::GetWidth() const {
  return width;
}
int VideoMemory::CheckX(int x) const {
  if (x >= width || x < 0) {
    std::cout << "[WARN][VideoMemory]: X is out of bound, should be [0, " << width << "), but " << x << std::endl;
    return std::clamp(x, 0, width-1);
  }
  return x;
}
int VideoMemory::CheckY(int y) const {
  if (y >= height || y < 0) {
    std::cout << "[WARN][VideoMemory]: Y is out of bound, should be [0, " << height << "), but " << y << std::endl;
    return std::clamp(y, 0, height-1);
  }
  return y;
}
