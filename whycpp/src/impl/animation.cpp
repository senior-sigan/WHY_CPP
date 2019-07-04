#include <whycpp/animation.h>
#include <whycpp/drawing.h>
#include <whycpp/time.h>
#include <whycpp/types.h>

Animation::Animation(i32 width, i32 height, i32 speed, std::vector<std::pair<int, int>> sprites, i32 sprite_id,
                     bool cycle)
    : width(width), height(height), sprite_id(sprite_id), speed(speed), cycle(cycle), sprites(std::move(sprites)) {}
void Animation::Draw(Context &ctx, i32 x, i32 y) {
  time += GetDelta(ctx);
  if (sprites.empty()) {
    return;
  }
  auto index = sprites.size() - 1;
  if (!full_cycle) {
    index = static_cast<u64>(time * speed) % sprites.size();
    if (index == sprites.size() - 1 && !cycle) {
      full_cycle = true;
    }
  }
  auto spr = sprites.at(index);
  DrawSprite(ctx, sprite_id, x, y, spr.first, spr.second, width, height);
}
