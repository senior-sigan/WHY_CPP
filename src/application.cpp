#include "application.h"
#include "logger.h"
#include <SDL2/SDL.h>

Application::Application(ApplicationListener *const listener, int width, int height) : listener(listener) {
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
Application::~Application() {
  delete texture;
  delete vram;
  SDL_DestroyRenderer(ren);
  SDL_DestroyWindow(win);
  SDL_Quit();
}
void Application::Run() {
  Context ctx(*vram);
  listener->OnCreate(ctx);
  auto now = SDL_GetPerformanceCounter();
  auto last = now;
  double delta_time = 0.0;
  while (!quit) {
    last = now;
    now = SDL_GetPerformanceCounter();
    delta_time = ((now - last) * 1000) / static_cast<double>(SDL_GetPerformanceFrequency());
    delta_time /= 1000.0; // convert to seconds
    ctx.Tick(delta_time);
    HandleEvents();
    listener->OnRender(ctx);
    Render();
  }
  listener->OnDispose(ctx);
}
void Application::Render() {
  SDL_RenderClear(ren);
  texture->Render();
  SDL_RenderPresent(ren);
}
void Application::HandleEvents() {
  SDL_Event e;
  while (SDL_PollEvent(&e)) {
    if (e.type == SDL_QUIT) {
      quit = true;
    }
  }
}
