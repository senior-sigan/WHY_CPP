#include "audio_holder.h"
#include "../logger.h"

void AudioHolder::RegisterMusic(const std::string& path, const std::string& name) {
  LOG_DEBUG("Registered music %s : %s", path.c_str(), name.c_str());
  musics_[name] = std::make_unique<Music>(path);
}
Music* AudioHolder::GetMusic(const std::string& name) const {
  if (musics_.count(name) == 0) {
    LOG_WARN("There is no music for '%s'", name.c_str());
    return nullptr;
  }
  return musics_.at(name).get();
}
void AudioHolder::RegisterSFX(const std::string& path, const std::string& name) {
  LOG_DEBUG("Registered SFX %s : %s", path.c_str(), name.c_str());
  sfxs_[name] = std::make_unique<SFX>(path);
}
SFX* AudioHolder::GetSFX(const std::string& name) const {
  if (sfxs_.count(name) == 0) {
    LOG_WARN("There is no sfx for '%s'", name.c_str());
    return nullptr;
  }
  return sfxs_.at(name).get();
}
AudioHolder::~AudioHolder() {}
