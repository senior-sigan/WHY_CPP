#include <whycpp/animation.h>
#include <whycpp/drawing.h>
#include <whycpp/time.h>

Animation::Animation(int width, int height, int speed, std::vector<std::pair<int, int>> sprites, int sprite_id,
                     bool cycle)
    : width(width), height(height), sprite_id(sprite_id), speed(speed), cycle(cycle), sprites(std::move(sprites)) {}
void Animation::Draw(int x, int y) {
  time += GetDelta();
  if (sprites.empty()) {
    return;
  }
  auto index = sprites.size() - 1;
  if (!full_cycle) {
    index = static_cast<unsigned long>(time * speed) % sprites.size();
    if (index == sprites.size() - 1 && !cycle) {
      full_cycle = true;
    }
  }
  auto spr = sprites.at(index);
  DrawSprite(sprite_id, x, y, spr.first, spr.second, width, height);
}
