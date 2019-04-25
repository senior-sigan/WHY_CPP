#include "sdl_context.h"
#include "sdl_audio_context.h"
#include "sdl_render_context.h"

SDLContext::SDLContext(const ApplicationConfig& config, VideoMemory* vram)
    : render_(std::make_unique<SDLRenderContext>(config, vram)), audio_(std::make_unique<SDLAudioContext>()) {}
SDLRenderContext* SDLContext::GetRenderer() const {
  return render_.get();
}
SDLContext::~SDLContext() = default;
