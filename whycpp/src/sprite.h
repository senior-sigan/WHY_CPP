#pragma once

#include <whycpp/color.h>
#include <whycpp/types.h>
#include <memory>
#include <vector>

class Sprite {
  i32 width_;
  i32 height_;
  std::vector<std::vector<RGBA>> texture;

  size_t CheckX(i32 x) const;
  size_t CheckY(i32 y) const;

 public:
  Sprite(i32 width, i32 height);
  ~Sprite();
  i32 GetWidth() const;
  i32 GetHeight() const;
  const RGBA &Get(i32 x, i32 y) const;
  void Set(i32 x, i32 y, const RGBA &color);
};
