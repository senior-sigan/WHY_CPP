#include "sdl_context.h"
#include <SDL2/SDL.h>
#include <whycpp/application_config.h>
#include "logger.h"
#include "sdl_texture.h"
#include "video_memory.h"
#include "sdl_deleter.h"

SDLContext::SDLContext(const ApplicationConfig& config, VideoMemory* vram) {
  if (SDL_Init(SDL_INIT_VIDEO) != 0) {
    logSDLError("SDL_Init");
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
    logSDLError("SDL_CreateWindow");
    return;  // TODO: what? throw exception?
  }
  ren = std::unique_ptr<SDL_Renderer, sdl_deleter>(
      SDL_CreateRenderer(win.get(), -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC), sdl_deleter());
  if (!ren) {
    logSDLError("SDL_CreateRenderer");
    return;  // TODO: what? throw exception?
  }
  texture = std::unique_ptr<SDLTexture>(new SDLTexture(ren, *vram));
}
SDLContext::~SDLContext() {
  SDL_Quit();
}
void SDLContext::Render() {
  SDL_RenderClear(ren.get());
  texture->Render();
  SDL_RenderPresent(ren.get());
}
