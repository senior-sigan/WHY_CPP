#include <memory>

#include "sdl_render_context.h"
#include <SDL.h>
#include <whycpp/application_config.h>
#include "../logger.h"
#include "../video_memory.h"
#include "sdl_deleter.h"
#include "sdl_texture.h"

SDLRenderContext::SDLRenderContext(const ApplicationConfig& config, VideoMemory* vram) {
  LOG_DEBUG("SDLRenderContext created");
  if (SDL_Init(SDL_INIT_VIDEO) != 0) {
    LogSDLError("SDL_Init");
    return;  // TODO: what? throw exception?
  }
  Uint32 flags = SDL_WINDOW_SHOWN;
  if (config.is_fullscreen) {
    flags |= SDL_WINDOW_FULLSCREEN_DESKTOP;
  } else {
    flags |= SDL_WINDOW_RESIZABLE;
  }
  win = std::unique_ptr<SDL_Window, sdl_deleter>(
      SDL_CreateWindow(config.name.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, config.GetWindowWidth(),
                       config.GetWindowHeight(), flags),
      sdl_deleter());
  if (!win) {
    LogSDLError("SDL_CreateWindow");
    return;  // TODO: what? throw exception?
  }
  auto vsync = 0u;
  if (config.vsync) {
    vsync = SDL_RENDERER_PRESENTVSYNC;
  }
  ren = std::unique_ptr<SDL_Renderer, sdl_deleter>(
      SDL_CreateRenderer(win.get(), -1, SDL_RENDERER_ACCELERATED | vsync), sdl_deleter());
  if (!ren) {
    LogSDLError("SDL_CreateRenderer");
    return;  // TODO: what? throw exception?
  }
  auto info = std::make_unique<SDL_RendererInfo>();
  SDL_GetRendererInfo(ren.get(), info.get());
  LOG_INFO("Renderer info: name=%s", info->name);
  texture = std::make_unique<SDLTexture>(ren.get(), vram);
}
SDLRenderContext::~SDLRenderContext() {
  LOG_DEBUG("SDLRenderContext destroyed");
  SDL_Quit();
}
void SDLRenderContext::Render() {
  SDL_RenderClear(ren.get());
  texture->Render();
  SDL_RenderPresent(ren.get());
}
