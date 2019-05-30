#include <SDL_events.h>
#include <whycpp/application_listener.h>
#include "../context.h"
#include "../global_app_context.h"
#include "../inputs_handler.h"
#include "../video_memory.h"

void InputsHandler::HandleEvents() {
  auto& ctx = GetContext();
  SDL_Event e;
  ctx.ResetKeys();
  int x, y;
  SDL_GetMouseState(&x, &y);
  if (ctx.GetVRAM()->GetScreenHeight() != 0) {
    ctx.mousePosY = y * ctx.GetVRAM()->GetHeight() / ctx.GetVRAM()->GetScreenHeight();
  }
  if (ctx.GetVRAM()->GetScreenWidth() != 0) {
    ctx.mousePosX = x * ctx.GetVRAM()->GetWidth() / ctx.GetVRAM()->GetScreenWidth();
  }
  while (SDL_PollEvent(&e)) {
    if (e.type == SDL_QUIT || e.type == SDL_APP_TERMINATING) {
      ctx.SetQuit(true);
    }
    if (e.type == SDL_APP_WILLENTERBACKGROUND || e.type == SDL_APP_DIDENTERBACKGROUND) {
      ctx.SetPaused(true);
      // TODO: may be send event?
//      listener_->OnPause();
    }
    if (e.type == SDL_APP_WILLENTERFOREGROUND || e.type == SDL_APP_DIDENTERFOREGROUND) {
      ctx.SetPaused(false);
      // TODO: may be send event?
//      listener_->OnResume();
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
