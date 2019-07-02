#include <SDL_timer.h>
#include <whycpp/types.h>
#include "../timing.h"

i64 GetTicks() {
  return static_cast<i64>(SDL_GetTicks());
}

void Delay(u32 time) {
  SDL_Delay(time);
}
