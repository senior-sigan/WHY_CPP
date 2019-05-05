#include "context.h"
#include <whycpp/buttons.h>
#include <whycpp/font.h>
#include <memory>
#include "audio.h"
#include "logger.h"
#include "video_memory.h"
#include "sprite.h"

void Context::KeyUp(const unsigned int code) {
  if (code >= KEY_NUM_KEYS) return;
  buttons_[code] = false;
  clicked_[code] = true;
  LOG_INFO("KeyUp=%d", code);
}
void Context::KeyDown(const unsigned int code) {
  if (code >= KEY_NUM_KEYS) return;
  buttons_[code] = true;
  clicked_[code] = false;
  LOG_INFO("KeyDown=%d", code);
}
void Context::ResetKeys() {
  for (unsigned int i = 0; i < KEY_NUM_KEYS; i++) {
    clicked_[i] = false;
  }
}
void Context::Tick(double delta) {
  current_delta_ = delta;
  time_ += delta;
}
bool Context::IsQuit() const {
  return quit_;
}
void Context::SetQuit(bool quit) {
  quit_ = quit;
}
bool Context::IsPaused() const {
  return paused_;
}
void Context::SetPaused(bool paused) {
  paused_ = paused;
}
Font* Context::GetFont() const {
  return font_.get();
}
void Context::SetFont(Font* font) {
  Context::font_ = std::unique_ptr<Font>(font);
}
int Context::AppendSprite(Sprite* sprite) {
  sprites_.push_back(std::unique_ptr<Sprite>(sprite));
  return static_cast<int>(sprites_.size() - 1);
}
Sprite* Context::GetSprite(int index) const {
  return sprites_.at(static_cast<unsigned long>(index)).get();
}
Context::~Context() {
  LOG_DEBUG("Context destroyed");
}
Context::Context(VideoMemory* vram, Font* font)
    : vram_(std::unique_ptr<VideoMemory>(vram)), font_(std::unique_ptr<Font>(font)) {
  buttons_.resize(Button::KEY_NUM_KEYS);
  clicked_.resize(Button::KEY_NUM_KEYS);
  LOG_DEBUG("Context created");
}
VideoMemory* Context::GetVRAM() const {
  return vram_.get();
}
bool Context::IsButtonPressed(const Button& btn) const {
  if (static_cast<unsigned>(btn) >= buttons_.size()) return false;
  return buttons_.at(btn);
}
bool Context::IsButtonReleased(const Button& btn) const {
  if (static_cast<unsigned>(btn) >= buttons_.size()) return false;
  return clicked_.at(btn);
}
void Context::RegisterMusic(const std::string& path, const std::string& name) {
  LOG_DEBUG("Registered music %s : %s", path.c_str(), name.c_str());
  musics_[name] = std::make_unique<Music>(path);
}
Music* Context::GetMusic(const std::string& name) const {
  if (musics_.count(name) == 0) {
    LOG_WARN("There is no music for '%s'", name.c_str());
    return nullptr;
  }
  return musics_.at(name).get();
}
void Context::RegisterSFX(const std::string& path, const std::string& name) {
  LOG_DEBUG("Registered SFX %s : %s", path.c_str(), name.c_str());
  sfxs_[name] = std::make_unique<SFX>(path);
}
SFX* Context::GetSFX(const std::string& name) const {
  if (sfxs_.count(name) == 0) {
    LOG_WARN("There is no sfx for '%s'", name.c_str());
    return nullptr;
  }
  return sfxs_.at(name).get();
}
