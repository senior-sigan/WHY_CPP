#pragma once

#include <memory>
#include "../loop/i_render_handler.h"
#include "sdl_deleter.h"

struct ApplicationConfig;
class VideoMemoryHolder;
class SDLTexture;
struct SDL_Window;
struct SDL_Renderer;

class SDLRenderContext: public IRenderHandler {
  std::unique_ptr<SDL_Renderer, sdl_deleter> ren;
  std::unique_ptr<SDL_Window, sdl_deleter> win;
  std::unique_ptr<SDLTexture> texture;

 public:
  explicit SDLRenderContext(const ApplicationConfig& config, VideoMemoryHolder* vram);
  ~SDLRenderContext() override;

  void Render() override;
};
