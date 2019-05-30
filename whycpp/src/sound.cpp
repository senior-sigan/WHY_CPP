#include <whycpp/sound.h>
#include <string>
#include "audio.h"
#include "context.h"
#include "global_app_context.h"

void ImportMusic(const std::string& path, const std::string& name) {
  GetContext().RegisterMusic(path, name);
}
void ImportSFX(const std::string& path, const std::string& name) {
  GetContext().RegisterSFX(path, name);
}
void PlayMusic(const std::string& name, int loops) {
  GetContext().GetMusic(name)->Play(loops);
}
void PlaySFX(const std::string& name, int loops, int ticks) {
  GetContext().GetSFX(name)->Play(loops, ticks, -1);
}
void StopMusic(const std::string &name) {
  GetContext().GetMusic(name)->Stop();
}
void StopSFX(const std::string &name) {
  GetContext().GetSFX(name)->Stop();
}