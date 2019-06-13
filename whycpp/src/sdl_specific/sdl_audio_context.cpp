#include "sdl_audio_context.h"
#include <SDL.h>
#include <whycpp/log.h>

#if __EMSCRIPTEN__
#include <SDL2/SDL_mixer.h>
#else
#include <SDL_mixer.h>
#endif

#include "../logger.h"

SDLAudioContext::SDLAudioContext() {
  LOG_DEBUG("SDLAudioContext created");
  if (SDL_Init(SDL_INIT_AUDIO) != 0) {
    LogSDLError("SDL_INIT_AUDIO");
    return;
  }
  if (Mix_OpenAudio(MIX_DEFAULT_FREQUENCY, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024) != 0) {
    LOG_ERROR("SDL_MIXER error: %s", SDL_GetError());
  }
}
SDLAudioContext::~SDLAudioContext(){
  LOG_DEBUG("SDLAudioContext destroyed");
  Mix_CloseAudio();
}