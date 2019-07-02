#pragma once

#include <whycpp/types.h>
#include <string>

typedef struct _Mix_Music Mix_Music;
struct Mix_Chunk;

class Music {
  std::string path_;
  Mix_Music* sound_;

 public:
  explicit Music(const std::string& path);
  void Play(i32 loops);
  void Stop();
  virtual ~Music();
};

class SFX {
  std::string path_;
  Mix_Chunk* sound_;
  i32 channel_ = -1;

 public:
  explicit SFX(const std::string& path);
  void Play(i32 loops, i32 ticks, i32 channel);
  void Stop();
  virtual ~SFX();
};
