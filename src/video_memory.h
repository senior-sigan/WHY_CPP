#ifndef WHYCPP_VIDEO_MEMORY_H
#define WHYCPP_VIDEO_MEMORY_H

struct RGBA;

/**
 * @defgroup DrawingInternals Drawing
 * @ingroup Internals
 * @brief Internal drawing implementations.
 *
 * @{
 */

/**
 * @class VideoMemory
 * Holds information about screen pixels in the RGBA matrix.
 */
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

  int CheckX(int x) const;
  int CheckY(int y) const;
};

/** @} */

#endif //WHYCPP_VIDEO_MEMORY_H
