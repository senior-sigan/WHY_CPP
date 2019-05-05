#ifndef WHYCPP_ROOT_WHYCPP_SRC_SPRITE_H_
#define WHYCPP_ROOT_WHYCPP_SRC_SPRITE_H_

#include <whycpp/color.h>
#include <memory>
#include <vector>

class Sprite {
  int width_;
  int height_;
  std::vector<std::vector<RGBA>> texture;

  size_t CheckX(int x) const;
  size_t CheckY(int y) const;
 public:
  Sprite(int width, int height);
  ~Sprite();
  int GetWidth() const;
  int GetHeight() const;
  const RGBA &Get(int x, int y) const;
  void Set(int x, int y, const RGBA &color);
};

#endif //WHYCPP_ROOT_WHYCPP_SRC_SPRITE_H_
