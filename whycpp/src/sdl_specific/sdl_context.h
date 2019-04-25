#ifndef WHYCPP_ROOT_WHYCPP_SRC_SDL_SPECIFIC_SDL_CONTEXT_H_
#define WHYCPP_ROOT_WHYCPP_SRC_SDL_SPECIFIC_SDL_CONTEXT_H_

#include <memory>

class SDLAudioContext;
class SDLRenderContext;
struct ApplicationConfig;
class VideoMemory;

class SDLContext {
  std::unique_ptr<SDLRenderContext> render_;
  std::unique_ptr<SDLAudioContext> audio_;

 public:
  SDLContext(const ApplicationConfig& config, VideoMemory* vram);
  virtual ~SDLContext();
  SDLRenderContext* GetRenderer() const;
};

#endif  // WHYCPP_ROOT_WHYCPP_SRC_SDL_SPECIFIC_SDL_CONTEXT_H_
