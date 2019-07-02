#include <whycpp/sound.h>
#include <whycpp/types.h>
#include <string>
#include "audio.h"
#include "context.h"

void ImportMusic(Context& context, const std::string& path, const std::string& name) {
  context.RegisterMusic(path, name);
}
void ImportSFX(Context& context, const std::string& path, const std::string& name) {
  context.RegisterSFX(path, name);
}
void PlayMusic(const Context& context, const std::string& name, i32 loops) {
  context.GetMusic(name)->Play(loops);
}
void PlaySFX(const Context& context, const std::string& name, i32 loops, i32 ticks) {
  context.GetSFX(name)->Play(loops, ticks, -1);
}
void StopMusic(const Context& context, const std::string& name) {
  context.GetMusic(name)->Stop();
}
void StopSFX(const Context& context, const std::string& name) {
  context.GetSFX(name)->Stop();
}
