#include "application.h"
#include "logger.h"
#include <SDL2/SDL.h>
#include "sdl_texture.h"
#include "video_memory.h"
#include "context.h"
#include <whycpp/application_config.h>
#include <whycpp/application_listener.h>

Application::Application(
    const std::shared_ptr<ApplicationListener> listener,
    const ApplicationConfig &config
) : listener(listener) {
  if (SDL_Init(SDL_INIT_VIDEO) != 0) {
    logSDLError("SDL_Init");
    return; // TODO: what? throw exception?
  }
  Uint32 flags = SDL_WINDOW_SHOWN;
  if (config.is_fullscreen) {
    flags |= SDL_WINDOW_FULLSCREEN_DESKTOP;
  } else {
    flags |= SDL_WINDOW_RESIZABLE;
  }
  win = std::unique_ptr<SDL_Window, sdl_deleter>(
      SDL_CreateWindow(config.name.c_str(),
                       SDL_WINDOWPOS_CENTERED,
                       SDL_WINDOWPOS_CENTERED,
                       config.width,
                       config.height,
                       flags), sdl_deleter());
  if (!win) {
    logSDLError("SDL_CreateWindow");
    return; // TODO: what? throw exception?
  }
  ren = std::unique_ptr<SDL_Renderer, sdl_deleter>(
      SDL_CreateRenderer(win.get(), -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC),
      sdl_deleter()
  );
  if (!ren) {
    logSDLError("SDL_CreateRenderer");
    return; // TODO: what? throw exception?
  }
  vram = std::make_shared<VideoMemory>(config.width, config.height);
  texture = std::make_shared<SDLTexture>(ren, *vram);
}
Application::~Application() {
  SDL_Quit();
}
void Application::Run() {
  Context ctx(*vram);
  listener->OnCreate(ctx);
  auto now = SDL_GetPerformanceCounter();
  auto last = now;
  double delta_time = 0.0;
  while (!ctx.IsQuit()) {
    last = now;
    now = SDL_GetPerformanceCounter();
    delta_time = ((now - last) * 1000) / static_cast<double>(SDL_GetPerformanceFrequency());
    delta_time /= 1000.0; // convert to seconds
    HandleEvents(ctx);
    if (!ctx.IsPaused()) {
      ctx.Tick(delta_time);
      listener->OnRender(ctx);
      Render();
    }
  }
  listener->OnDispose(ctx);
}
void Application::Render() {
  SDL_RenderClear(ren.get());
  texture->Render();
  SDL_RenderPresent(ren.get());
}
void Application::HandleEvents(Context &ctx) {
  SDL_Event e;
  ctx.ResetKeys();
  while (SDL_PollEvent(&e)) {
    if (e.type == SDL_QUIT || e.type == SDL_APP_TERMINATING) {
      ctx.SetQuit(true);
    }
    if (e.type == SDL_APP_WILLENTERBACKGROUND || e.type == SDL_APP_DIDENTERBACKGROUND) {
      ctx.SetPaused(true);
      listener->OnPause(ctx);
    }
    if (e.type == SDL_APP_WILLENTERFOREGROUND || e.type == SDL_APP_DIDENTERFOREGROUND) {
      ctx.SetPaused(false);
      listener->OnResume(ctx);
    }
    if (e.type == SDL_KEYDOWN) {
      ctx.KeyDown(e.key.keysym);
    }
    if (e.type == SDL_KEYUP) {
      ctx.KeyUp(e.key.keysym);
    }
  }
}
