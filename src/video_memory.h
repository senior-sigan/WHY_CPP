#ifndef WHYCPP_VIDEO_MEMORY_H
#define WHYCPP_VIDEO_MEMORY_H

struct RGBA;

class VideoMemory {
 public:
  int GetWidth() const;
  int GetHeight() const;
  const RGBA &Get(int x, int y) const;
  void Set(int x, int y, const RGBA &color);
  explicit VideoMemory(int width, int height);
  virtual ~VideoMemory();
 private:
  int width;
  int height;
  RGBA **texture;
};

#endif //WHYCPP_VIDEO_MEMORY_H
