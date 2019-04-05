//
// Created by k.leyfer on 29.03.2019.
//

#ifndef WHYCPP_ROOT_ANIMATION_H
#define WHYCPP_ROOT_ANIMATION_H

#include <whycpp/c_api.h>

typedef struct {
  int first;
  int second;
} Pair_t;

struct Animation_t_;

typedef struct Animation_t_ Animation_t;

WHYCPP_C_API
Animation_t* MakeAnimation_C(int width, int height, int speed, Pair_t* sprites, unsigned int sprites_count,
                             int sprite_id, bool cycle);

WHYCPP_C_API
void DrawAnimation_C(Animation_t* animation, int x, int y);

#endif  // WHYCPP_ROOT_ANIMATION_H
