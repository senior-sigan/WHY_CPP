#ifndef WHYCPP_ROOT_WHYCPP_SRC_SDL_SPECIFIC_AUDIO_H_
#define WHYCPP_ROOT_WHYCPP_SRC_SDL_SPECIFIC_AUDIO_H_

#include <string>

typedef struct _Mix_Music Mix_Music;
struct Mix_Chunk;

class Music {
  std::string path_;
  Mix_Music* sound_;

 public:
  explicit Music(const std::string& path);
  void Play(int loops);
  virtual ~Music();
};

class SFX {
  std::string path_;
  Mix_Chunk* sound_;

 public:
  explicit SFX(const std::string& path);
  void Play(int loops, int ticks, int channel);
  virtual ~SFX();
};

#endif  // WHYCPP_ROOT_WHYCPP_SRC_SDL_SPECIFIC_AUDIO_H_
