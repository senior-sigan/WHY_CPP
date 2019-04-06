#ifndef WHYCPP_SDL_CONTEXT_H
#define WHYCPP_SDL_CONTEXT_H

#include <memory>
#include "sdl_deleter.h"

struct ApplicationConfig;
class VideoMemory;
class SDLTexture;
struct SDL_Window;
struct SDL_Renderer;

class SDLContext {
  std::unique_ptr<SDL_Renderer, sdl_deleter> ren;
  std::unique_ptr<SDL_Window, sdl_deleter> win;
  std::unique_ptr<SDLTexture> texture;

 public:
  explicit SDLContext(const ApplicationConfig& config, VideoMemory* vram);
  virtual ~SDLContext();

  void Render();
};

#endif  // WHYCPP_SDL_CONTEXT_H
