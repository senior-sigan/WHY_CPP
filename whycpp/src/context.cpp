#include "context.h"
#include <whycpp/buttons.h>
#include <whycpp/font.h>
#include <memory>
#include "logger.h"
#include "video_memory.h"

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
Font* Context::GetFont() const {
  return font.get();
}
void Context::SetFont(Font* font) {
  Context::font = std::unique_ptr<Font>(font);
}
int Context::AppendSprite(VideoMemory* sprite) {
  sprites.push_back(std::unique_ptr<VideoMemory>(sprite));
  return static_cast<int>(sprites.size() - 1);
}
VideoMemory* Context::GetSprite(int index) const {
  return sprites.at(static_cast<unsigned long>(index)).get();
}
Context::~Context() {
  LOG_DEBUG("Context destroyed");
}
Context::Context(VideoMemory* vram, Font* font) : vram(std::unique_ptr<VideoMemory>(vram)), font(std::unique_ptr<Font>(font)) {
  buttons.resize(Button::KEY_NUM_KEYS);
  clicked.resize(Button::KEY_NUM_KEYS);
  LOG_DEBUG("Context created");
}
VideoMemory* Context::GetVRAM() const {
  return vram.get();
}
bool Context::IsButtonPressed(const Button& btn) const {
  if (static_cast<unsigned>(btn) >= buttons.size()) return false;
  return buttons.at(btn);
}
bool Context::IsButtonReleased(const Button& btn) const {
  if (static_cast<unsigned>(btn) >= buttons.size()) return false;
  return clicked.at(btn);
}
