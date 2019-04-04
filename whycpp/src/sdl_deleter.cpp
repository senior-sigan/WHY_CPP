#include "sdl_deleter.h"
#include <SDL.h>

void sdl_deleter::operator()(SDL_Window *p) const {
  SDL_DestroyWindow(p);
}
void sdl_deleter::operator()(SDL_Renderer *p) const {
  SDL_DestroyRenderer(p);
}
void sdl_deleter::operator()(SDL_Texture *p) const {
  SDL_DestroyTexture(p);
}
