#include "application.h"
#include <SDL2/SDL.h>
#include <whycpp/application_config.h>
#include <whycpp/application_listener.h>
#include <functional>
#include "context.h"
#include "default_font.h"
#include "logger.h"
#include "loop.h"
#include "sdl_texture.h"
#include "video_memory.h"

Application::Application(ApplicationListener* listener, const ApplicationConfig& config)
    : listener(std::unique_ptr<ApplicationListener>(listener)) {
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
  vram = std::unique_ptr<VideoMemory>(new VideoMemory(config.width, config.height));
  texture = std::unique_ptr<SDLTexture>(new SDLTexture(ren, *vram));
}
Application::~Application() {
  SDL_Quit();
}
void Application::Run() {
  auto font = BuildDefaultFont();
  Context ctx(*vram, font);
  Loop::Callback lambda = [=](Context& ctx, double delta_time) { Update(ctx, delta_time); };
  Loop loop(lambda, ctx);

  listener->OnCreate(ctx);
  loop.Run();
  listener->OnDispose(ctx);
}
void Application::Update(Context& ctx, double delta_time) {
  HandleEvents(ctx);
  if (!ctx.IsPaused()) {
    ctx.Tick(delta_time);
    listener->OnRender(ctx);
    Render();
  }
}
void Application::Render() {
  SDL_RenderClear(ren.get());
  texture->Render();
  SDL_RenderPresent(ren.get());
}
void Application::HandleEvents(Context& ctx) {
  SDL_Event e;
  ctx.ResetKeys();
  int x, y;
  SDL_GetMouseState(&x, &y);
  if (ctx.GetVRAM().GetScreenHeight() != 0) {
    ctx.mousePosY = y * ctx.GetVRAM().GetHeight() / ctx.GetVRAM().GetScreenHeight();
  }
  if (ctx.GetVRAM().GetScreenWidth() != 0) {
    ctx.mousePosX = x * ctx.GetVRAM().GetWidth() / ctx.GetVRAM().GetScreenWidth();
  }
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
      ctx.KeyDown(e.key.keysym.scancode);
    }
    if (e.type == SDL_KEYUP) {
      ctx.KeyUp(e.key.keysym.scancode);
    }
    if (e.type == SDL_MOUSEBUTTONUP) {
      ctx.KeyUp(e.button.button + 256u);
    }
    if (e.type == SDL_MOUSEBUTTONDOWN) {
      ctx.KeyDown(e.button.button + 256u);
    }
  }
}
