#include <SDL2/SDL_keyboard.h>
#include "context.h"
#include <iostream>

void Context::KeyUp(const SDL_Keysym &keysym) {
  if (static_cast<int>(keysym.scancode) >= KEY_NUM_KEYS) return;
  buttons[keysym.scancode] = false;
  clicked[keysym.scancode] = true;
}
void Context::KeyDown(const SDL_Keysym &keysym) {
  if (static_cast<int>(keysym.scancode) >= KEY_NUM_KEYS) return;
  buttons[keysym.scancode] = true;
  clicked[keysym.scancode] = false;
}
void Context::ResetKeys() {
  for (int i = 0; i < KEY_NUM_KEYS; i++) {
    clicked[i] = false;
  }
}
void Context::Tick(double delta) {
  current_delta = delta;
  time += delta;
}
bool Context::IsQuit() const {
  return quit;
}
void Context::SetQuit(bool quit) {
  Context::quit = quit;
}
bool Context::IsPaused() const {
  return paused;
}
void Context::SetPaused(bool paused) {
  Context::paused = paused;
}
