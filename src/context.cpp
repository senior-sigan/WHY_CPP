#include <SDL2/SDL_keyboard.h>
#include "context_impl.h"
#include <iostream>

void Context::KeyUp(const SDL_Keysym &keysym) {
  std::cout << "UP " << keysym.scancode << std::endl;
}
void Context::KeyDown(const SDL_Keysym &keysym) {
  std::cout << "DOWN" << keysym.scancode << std::endl;
}
void Context::Tick(double delta) {
  current_delta = delta;
  time += delta;
}
