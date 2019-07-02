#include <whycpp/log.h>
#include <whycpp/types.h>
#include "../audio.h"

#include <SDL.h>
#if __EMSCRIPTEN__
#include <SDL2/SDL_mixer.h>
#else
#include <SDL_mixer.h>
#endif

void Music::Play(i32 loops) {
  if (Mix_PlayMusic(sound_, loops) != 0) {
    LOG_WARN("Cannot play music %s: %s", path_.c_str(), SDL_GetError());
  }
}
void Music::Stop() {
  if (Mix_HaltMusic() != 0) {
    LOG_WARN("Cannot stop music %s: %s", path_.c_str(), SDL_GetError());
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
void SFX::Play(i32 loops, i32 ticks, i32 channel) {
  channel_ = Mix_PlayChannelTimed(channel, sound_, loops, ticks);
  if (channel_ != 0) {
    LOG_WARN("Cannot play effect %s: %s", path_.c_str(), SDL_GetError());
  }
}
void SFX::Stop() {
  if (Mix_HaltChannel(channel_) != 0) {
    LOG_WARN("Cannot stop effect %s: %s", path_.c_str(), SDL_GetError());
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
