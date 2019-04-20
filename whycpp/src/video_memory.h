#ifndef WHYCPP_VIDEO_MEMORY_H
#define WHYCPP_VIDEO_MEMORY_H

#include <whycpp/color.h>
#include <memory>
#include <vector>

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
  int GetScreenWidth() const;
  void SetScreenWidth(int screen_width);
  int GetScreenHeight() const;
  void SetScreenHeight(int screen_height);
  int GetWidth() const;
  int GetHeight() const;
  const RGBA &Get(int x, int y) const;
  void Set(int x, int y, const RGBA &color);
  explicit VideoMemory(int width, int height);
  virtual ~VideoMemory();

 private:
  int width;
  int height;
  int screen_width = 0;
  int screen_height = 0;
  std::vector<std::vector<RGBA>> texture;

  size_t CheckX(int x) const;
  size_t CheckY(int y) const;
};

/** @} */

#endif  // WHYCPP_VIDEO_MEMORY_H
