#include <SDL_timer.h>
#include "../timing.h"

long GetTicks() {
  return static_cast<long>(SDL_GetTicks());
}

void Delay(uint32_t time) {
  SDL_Delay(time);
}