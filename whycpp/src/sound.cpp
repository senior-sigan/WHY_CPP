#include <whycpp/sound.h>
#include <whycpp/types.h>
#include <string>
#include "audio.h"
#include "context.h"
#include "holders/audio_holder.h"

void ImportMusic(Context& context, const std::string& path, const std::string& name) {
  context.Get<AudioHolder>()->RegisterMusic(path, name);
}
void ImportSFX(Context& context, const std::string& path, const std::string& name) {
  context.Get<AudioHolder>()->RegisterSFX(path, name);
}
void PlayMusic(const Context& context, const std::string& name, i32 loops) {
  context.Get<AudioHolder>()->GetMusic(name)->Play(loops);
}
void PlaySFX(const Context& context, const std::string& name, i32 loops, i32 ticks) {
  context.Get<AudioHolder>()->GetSFX(name)->Play(loops, ticks, -1);
}
void StopMusic(const Context& context, const std::string& name) {
  context.Get<AudioHolder>()->GetMusic(name)->Stop();
}
void StopSFX(const Context& context, const std::string& name) {
  context.Get<AudioHolder>()->GetSFX(name)->Stop();
}
