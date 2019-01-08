#ifndef WHYCPP_APPLICATION_H
#define WHYCPP_APPLICATION_H

#include <whycpp/SDLTexture.h>
#include <whycpp/logger.h>
#include <SDL2/SDL.h>
#include <whycpp/application_listener.h>

class Application {
 public:
  explicit Application(ApplicationListener *const listener, int width = 256, int height = 144) : listener(listener) {
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
      logSDLError("SDL_Init");
      return; // TODO: what? throw exception?
    }
    win = SDL_CreateWindow("Hello World!", 100, 100, width, height, SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);
    if (win == nullptr) {
      logSDLError("SDL_CreateWindow");
      return; // TODO: what? throw exception?
    }
    ren = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (ren == nullptr) {
      logSDLError("SDL_CreateRenderer");
      return; // TODO: what? throw exception?
    }
    vram = new VideoMemory(width, height);
    texture = new SDLTexture(ren, *vram);
  }
  virtual ~Application() {
    delete texture;
    delete vram;
    SDL_DestroyRenderer(ren);
    SDL_DestroyWindow(win);
    SDL_Quit();
  }

  void Run() {
    listener->OnCreate();
    Context ctx(*vram);
    while (!quit) {
      HandleEvents();
      listener->OnRender(ctx);
      Render();
    }
    listener->OnDispose();
  }
 private:
  SDL_Renderer *ren;
  SDL_Window *win;
  VideoMemory *vram;
  SDLTexture *texture;
  ApplicationListener *const listener;

  bool quit = false;

  void Render() {
    SDL_RenderClear(ren);
    texture->Render();
    SDL_RenderPresent(ren);
  }

  void HandleEvents() {
    SDL_Event e;
    while (SDL_PollEvent(&e)) {
      if (e.type == SDL_QUIT) {
        quit = true;
      }
    }
  }
};

#endif //WHYCPP_APPLICATION_H
