#include <whycpp/animation.h>
#include <whycpp_c/animation.h>
#include "internal/global_context_int.h"

std::vector<std::pair<int, int>> createSprites(Pair_t* sprites, unsigned int count) {
  std::vector<std::pair<int, int>> result;
  for (unsigned int i = 0; i < count; ++i) {
    result.emplace_back(sprites[i].first, sprites[i].second);
  }

  return result;
}

Animation_t* MakeAnimation_C(int width, int height, int speed, Pair_t* sprites, unsigned int sprites_count,
                             int sprite_id, bool cycle) {
  auto animation = new Animation(width, height, speed, createSprites(sprites, sprites_count), sprite_id, cycle);
  return reinterpret_cast<Animation_t*>(animation);
}

void DrawAnimation_C(Animation_t* animation, int x, int y) {
  reinterpret_cast<Animation*>(animation)->Draw(*GetContext_C(), x, y);
}
