#include "sprite.h"
#include <whycpp/log.h>
#include "int_utils.h"

Sprite::Sprite(int width, int height)
    : width_(width),
      height_(height),
      texture(std::vector<std::vector<RGBA>>(static_cast<unsigned long>(width),
                                             std::vector<RGBA>(static_cast<unsigned long>(height), {0, 0, 0, 0}))) {
  LOG_DEBUG("Sprite [%d, %d] created", width, height);
}
Sprite::~Sprite() {
  LOG_DEBUG("Sprite [%d, %d] destroyed", width_, height_);
}
void Sprite::Set(int x, int y, const RGBA &color) {
  texture.at(CheckX(x)).at(CheckY(y)) = color;
}
const RGBA &Sprite::Get(int x, int y) const {
  return texture.at(static_cast<unsigned long>(CheckX(x))).at(static_cast<unsigned long>(CheckY(y)));
}
int Sprite::GetHeight() const {
  return height_;
}
int Sprite::GetWidth() const {
  return width_;
}
size_t Sprite::CheckX(int x) const {
  if (x >= width_ || x < 0) {
    LOG_VERBOSE("Sprite:  X is out of bound, should be [0, %d) but %d", width_, x);
    return static_cast<size_t>(clamp(x, 0, width_ - 1));
  }
  return static_cast<size_t>(x);
}
size_t Sprite::CheckY(int y) const {
  if (y >= height_ || y < 0) {
    LOG_VERBOSE("Sprite:  Y is out of bound, should be [0, %d) but %d", height_, y);
    return static_cast<size_t>(clamp(y, 0, height_ - 1));
  }
  return static_cast<size_t>(y);
}