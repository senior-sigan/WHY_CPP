#include <SDL_events.h>
#include <whycpp/application_listener.h>
#include "../context.h"
#include "../holders/keyboard_holder.h"
#include "../holders/lifecycle_holder.h"
#include "../holders/mouse_holder.h"
#include "../inputs_handler.h"
#include "../video_memory.h"

void InputsHandler::HandleEvents(Context& ctx) {
  SDL_Event e;
  ctx.container->Get<KeyboardHolder>()->ResetKeys();
  i32 x, y;
  SDL_GetMouseState(&x, &y);
  if (ctx.container->Get<VideoMemory>()->GetScreenHeight() != 0) {
    ctx.container->Get<MouseHolder>()->mousePosY =
        y * ctx.container->Get<VideoMemory>()->GetHeight() / ctx.container->Get<VideoMemory>()->GetScreenHeight();
  }
  if (ctx.container->Get<VideoMemory>()->GetScreenWidth() != 0) {
    ctx.container->Get<MouseHolder>()->mousePosX =
        x * ctx.container->Get<VideoMemory>()->GetWidth() / ctx.container->Get<VideoMemory>()->GetScreenWidth();
  }
  while (SDL_PollEvent(&e)) {
    if (e.type == SDL_QUIT || e.type == SDL_APP_TERMINATING) {
      ctx.container->Get<LifecycleHolder>()->SetQuit(true);
    }
    if (e.type == SDL_APP_WILLENTERBACKGROUND || e.type == SDL_APP_DIDENTERBACKGROUND) {
      ctx.container->Get<LifecycleHolder>()->SetPaused(true);
      listener_->OnPause(ctx);
    }
    if (e.type == SDL_APP_WILLENTERFOREGROUND || e.type == SDL_APP_DIDENTERFOREGROUND) {
      ctx.container->Get<LifecycleHolder>()->SetPaused(false);
      listener_->OnResume(ctx);
    }
    if (e.type == SDL_KEYDOWN) {
      ctx.container->Get<KeyboardHolder>()->KeyDown(e.key.keysym.scancode);
    }
    if (e.type == SDL_KEYUP) {
      ctx.container->Get<KeyboardHolder>()->KeyUp(e.key.keysym.scancode);
    }
    if (e.type == SDL_MOUSEBUTTONUP) {
      ctx.container->Get<KeyboardHolder>()->KeyUp(e.button.button + 256u);
    }
    if (e.type == SDL_MOUSEBUTTONDOWN) {
      ctx.container->Get<KeyboardHolder>()->KeyDown(e.button.button + 256u);
    }
  }
}
InputsHandler::InputsHandler(ApplicationListener* listener) : listener_(listener) {}
