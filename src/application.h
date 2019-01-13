#ifndef WHYCPP_APPLICATION_H
#define WHYCPP_APPLICATION_H

#include <whycpp/application_listener.h>
#include <SDL2/SDL_video.h>
#include <SDL2/SDL_render.h>
#include "sdl_texture.h"
#include "video_memory.h"
#include "context_impl.h"

class Application {
 public:
  explicit Application(ApplicationListener *listener, int width = 256, int height = 144);
  virtual ~Application();

  void Run();
 private:
  SDL_Renderer *ren;
  SDL_Window *win;
  VideoMemory *vram;
  SDLTexture *texture;
  ApplicationListener *const listener;

  bool quit = false;

  void Render();

  void HandleEvents();
};

#endif //WHYCPP_APPLICATION_H
