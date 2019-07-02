#include "sprite.h"
#include <whycpp/log.h>
#include <whycpp/types.h>
#include "int_utils.h"

Sprite::Sprite(i32 width, i32 height)
    : width_(width),
      height_(height),
      texture(std::vector<std::vector<RGBA>>(static_cast<u64>(width),
                                             std::vector<RGBA>(static_cast<u64>(height), {0, 0, 0, 0}))) {
  LOG_DEBUG("Sprite [%d, %d] created", width, height);
}
Sprite::~Sprite() {
  LOG_DEBUG("Sprite [%d, %d] destroyed", width_, height_);
}
void Sprite::Set(i32 x, i32 y, const RGBA &color) {
  texture.at(CheckX(x)).at(CheckY(y)) = color;
}
const RGBA &Sprite::Get(i32 x, i32 y) const {
  return texture.at(static_cast<u64>(CheckX(x))).at(static_cast<u64>(CheckY(y)));
}
i32 Sprite::GetHeight() const {
  return height_;
}
i32 Sprite::GetWidth() const {
  return width_;
}
size_t Sprite::CheckX(i32 x) const {
  if (x >= width_ || x < 0) {
    LOG_VERBOSE("Sprite:  X is out of bound, should be [0, %d) but %d", width_, x);
    return static_cast<size_t>(clamp(x, 0, width_ - 1));
  }
  return static_cast<size_t>(x);
}
size_t Sprite::CheckY(i32 y) const {
  if (y >= height_ || y < 0) {
    LOG_VERBOSE("Sprite:  Y is out of bound, should be [0, %d) but %d", height_, y);
    return static_cast<size_t>(clamp(y, 0, height_ - 1));
  }
  return static_cast<size_t>(y);
}
