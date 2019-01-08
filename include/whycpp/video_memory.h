#ifndef WHYCPP_VIDEO_MEMORY_H
#define WHYCPP_VIDEO_MEMORY_H

#include <cstdint>

struct RGBA {
  uint8_t red;
  uint8_t green;
  uint8_t blue;
  uint8_t alpha;
};

class VideoMemory {
 public:
  int GetWidth() const {
    return width;
  }
  int GetHeight() const {
    return height;
  }

  const RGBA &Get(int x, int y) const {
    return texture[x][y];
  }

  void Set(int x, int y, const RGBA& color) {
    texture[x][y] = color;
  }

  explicit VideoMemory(int width, int height) : width(width), height(height) {
    texture = new RGBA *[width];
    for (int i = 0; i < width; i++) {
      texture[i] = new RGBA[height];
      for (int j = 0; j < height; j++) {
        texture[i][j] = {0, 0, 0, 0};
      }
    }
  }
  virtual ~VideoMemory() {
    for (int i = 0; i < width; i++) {
      delete[] texture[i];
    }
    delete[] texture;
  }
 private:
  int width;
  int height;
  RGBA **texture;
};

#endif //WHYCPP_VIDEO_MEMORY_H
