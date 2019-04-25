#include "../audio.h"
#include <whycpp/log.h>
#include <SDL_mixer.h>

void Music::Play(int loops) {
  if (Mix_PlayMusic(sound_, loops) != 0) {
    LOG_WARN("Cannot play music %s: %s", path_.c_str(), SDL_GetError());
  }
}
Music::Music(const std::string& path) : path_(path) {
  sound_ = Mix_LoadMUS(path.c_str());
  if (sound_ == nullptr) {
    LOG_ERROR("Cannot read music from file %s error: %s", path.c_str(), SDL_GetError());
    // TODO: throw exception
  }
}
Music::~Music() {
  Mix_FreeMusic(sound_);
}
void SFX::Play(int loops, int channel) {
  if (Mix_PlayChannel(channel, sound_, loops) != 0) {
    LOG_WARN("Cannot play effect %s: %s", path_.c_str(), SDL_GetError());
  }
}
SFX::SFX(const std::string& path) : path_(path) {
  sound_ = Mix_LoadWAV(path.c_str());
  if (sound_ == nullptr) {
    LOG_ERROR("Cannot read effect from file %s error: %s", path.c_str(), SDL_GetError());
    // TODO: throw exception
  }
}
SFX::~SFX() {
  Mix_FreeChunk(sound_);
}