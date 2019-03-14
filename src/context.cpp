#include "context.h"
#include <SDL2/SDL_keyboard.h>
#include <SDL2/SDL_mouse.h>
#include <whycpp/font.h>
#include <iostream>

void Context::KeyUp(const unsigned int code) {
  if (code >= KEY_NUM_KEYS) return;
  buttons[code] = false;
  clicked[code] = true;
}
void Context::KeyDown(const unsigned int code) {
  if (code >= KEY_NUM_KEYS) return;
  buttons[code] = true;
  clicked[code] = false;
}
void Context::ResetKeys() {
  for (unsigned int i = 0; i < KEY_NUM_KEYS; i++) {
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
Font& Context::GetFont() const {
  return font;
}
void Context::SetFont(const Font &font) {
  Context::font = font;
}
int Context::AppendSprite(const VideoMemory& sprite) {
  sprites.push_back(sprite);
  return static_cast<int>(sprites.size() - 1);
}
const VideoMemory& Context::GetSprite(int index) const {
  return sprites.at(static_cast<unsigned long>(index));
}
