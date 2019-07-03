#pragma once

#include <memory>
#include "sdl_deleter.h"

struct ApplicationConfig;
class VideoMemoryHolder;
class SDLTexture;
struct SDL_Window;
struct SDL_Renderer;

class SDLRenderContext {
  std::unique_ptr<SDL_Renderer, sdl_deleter> ren;
  std::unique_ptr<SDL_Window, sdl_deleter> win;
  std::unique_ptr<SDLTexture> texture;

 public:
  explicit SDLRenderContext(const ApplicationConfig& config, VideoMemoryHolder* vram);
  virtual ~SDLRenderContext();

  void Render();
};
