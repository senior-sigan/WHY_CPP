#include "application.h"
#include <SDL2/SDL.h>
#include <whycpp/application_config.h>
#include <whycpp/application_listener.h>
#include <functional>
#include "context.h"
#include "default_font.h"
#include "loop.h"
#include "sdl_texture.h"
#include "video_memory.h"
#include "sdl_context.h"

Application::Application(ApplicationListener* listener, const ApplicationConfig& config)
    : listener(std::unique_ptr<ApplicationListener>(listener)) {
  vram = std::unique_ptr<VideoMemory>(new VideoMemory(config.width, config.height));
  sdl_context = std::unique_ptr<SDLContext>(new SDLContext(config, vram.get()));
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
    sdl_context->Render();
  }
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
