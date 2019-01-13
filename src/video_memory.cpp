#include "video_memory.h"
#include <whycpp/color.h>

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
  texture[x][y] = color;
}
const RGBA &VideoMemory::Get(int x, int y) const {
  return texture[x][y];
}
int VideoMemory::GetHeight() const {
  return height;
}
int VideoMemory::GetWidth() const {
  return width;
}
