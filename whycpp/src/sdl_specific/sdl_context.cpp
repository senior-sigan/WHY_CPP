#include "sdl_context.h"
#include "sdl_audio_context.h"
#include "sdl_render_context.h"
#include "../holders/video_memory_holder.h"

SDLContext::SDLContext(const ApplicationConfig& config, VideoMemoryHolder* vram)
    : render_(std::make_unique<SDLRenderContext>(config, vram)), audio_(std::make_unique<SDLAudioContext>()) {}
SDLRenderContext* SDLContext::GetRenderer() const {
  return render_.get();
}
SDLContext::~SDLContext() = default;
