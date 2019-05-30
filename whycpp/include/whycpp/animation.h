#ifndef WHYCPP_ANIMATION_H
#define WHYCPP_ANIMATION_H

#include <utility>
#include <vector>

class Animation {
 private:
  const int width;
  const int height;
  const int sprite_id;
  int speed;
  bool cycle;
  std::vector<std::pair<int, int>> sprites;
  bool full_cycle = false;
  double time = 0;

 public:
  explicit Animation(int width, int height, int speed, std::vector<std::pair<int, int>> sprites, int sprite_id,
                     bool cycle);
  void Draw(int x, int y);
};

#endif  // WHYCPP_ANIMATION_H
