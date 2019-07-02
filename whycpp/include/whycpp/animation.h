#pragma once

#include <whycpp/types.h>
#include <utility>
#include <vector>

class Context;

class Animation {
 private:
  const i32 width;
  const i32 height;
  const i32 sprite_id;
  i32 speed;
  bool cycle;
  std::vector<std::pair<i32, i32>> sprites;
  bool full_cycle = false;
  double time = 0;

 public:
  explicit Animation(i32 width, i32 height, i32 speed, std::vector<std::pair<int, int>> sprites, i32 sprite_id,
                     bool cycle);
  void Draw(Context& ctx, i32 x, i32 y);
};
