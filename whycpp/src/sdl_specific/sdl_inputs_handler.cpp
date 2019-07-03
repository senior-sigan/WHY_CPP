#include <SDL_events.h>
#include <whycpp/application_listener.h>
#include "../context.h"
#include "../holders/keyboard_holder.h"
#include "../holders/lifecycle_holder.h"
#include "../holders/mouse_holder.h"
#include "../holders/video_memory_holder.h"
#include "../inputs_handler.h"

void InputsHandler::HandleEvents(Context& ctx) {
  SDL_Event e;
  ctx.Get<KeyboardHolder>()->ResetKeys();
  i32 x, y;
  SDL_GetMouseState(&x, &y);
  if (ctx.Get<VideoMemoryHolder>()->GetScreenHeight() != 0) {
    ctx.Get<MouseHolder>()->mousePosY =
        y * ctx.Get<VideoMemoryHolder>()->GetHeight() / ctx.Get<VideoMemoryHolder>()->GetScreenHeight();
  }
  if (ctx.Get<VideoMemoryHolder>()->GetScreenWidth() != 0) {
    ctx.Get<MouseHolder>()->mousePosX =
        x * ctx.Get<VideoMemoryHolder>()->GetWidth() / ctx.Get<VideoMemoryHolder>()->GetScreenWidth();
  }
  while (SDL_PollEvent(&e)) {
    if (e.type == SDL_QUIT || e.type == SDL_APP_TERMINATING) {
      ctx.Get<LifecycleHolder>()->SetQuit(true);
    }
    if (e.type == SDL_APP_WILLENTERBACKGROUND || e.type == SDL_APP_DIDENTERBACKGROUND) {
      ctx.Get<LifecycleHolder>()->SetPaused(true);
      listener_->OnPause(ctx);
    }
    if (e.type == SDL_APP_WILLENTERFOREGROUND || e.type == SDL_APP_DIDENTERFOREGROUND) {
      ctx.Get<LifecycleHolder>()->SetPaused(false);
      listener_->OnResume(ctx);
    }
    if (e.type == SDL_KEYDOWN) {
      ctx.Get<KeyboardHolder>()->KeyDown(e.key.keysym.scancode);
    }
    if (e.type == SDL_KEYUP) {
      ctx.Get<KeyboardHolder>()->KeyUp(e.key.keysym.scancode);
    }
    if (e.type == SDL_MOUSEBUTTONUP) {
      ctx.Get<KeyboardHolder>()->KeyUp(e.button.button + 256u);
    }
    if (e.type == SDL_MOUSEBUTTONDOWN) {
      ctx.Get<KeyboardHolder>()->KeyDown(e.button.button + 256u);
    }
  }
}
InputsHandler::InputsHandler(ApplicationListener* listener) : listener_(listener) {}
