#pragma once

#include <map>
#include <memory>
#include <string>
#include "../audio.h"
#include "../i_object.h"

class AudioHolder : public IObject {
  std::map<std::string, std::unique_ptr<Music>> musics_{};
  std::map<std::string, std::unique_ptr<SFX>> sfxs_{};

 public:
  void RegisterMusic(const std::string& path, const std::string& name);
  Music* GetMusic(const std::string& name) const;
  void RegisterSFX(const std::string& path, const std::string& name);
  SFX* GetSFX(const std::string& name) const;
  ~AudioHolder() override;
};
