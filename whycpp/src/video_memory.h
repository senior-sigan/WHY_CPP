#pragma once

#include <whycpp/color.h>
#include <whycpp/types.h>
#include <memory>
#include <vector>
#include "i_object.h"

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
class VideoMemory : public IObject {
 public:
  explicit VideoMemory(i32 width, i32 height);
  ~VideoMemory() override;

  i32 GetScreenWidth() const;
  void SetScreenWidth(i32 screen_width);
  i32 GetScreenHeight() const;
  void SetScreenHeight(i32 screen_height);
  i32 GetWidth() const;
  i32 GetHeight() const;
  const RGBA Get(i32 x, i32 y) const;
  void Set(i32 x, i32 y, const RGBA& color);
  void Fill(const RGBA& color);
  const uint8_t* GetBuffer() const;

 private:
  i32 width;
  i32 height;
  i32 screen_width = 0;
  i32 screen_height = 0;
  std::unique_ptr<uint32_t[]> buffer;

  inline size_t CheckX(i32 x) const;
  inline size_t CheckY(i32 y) const;
};

/** @} */
