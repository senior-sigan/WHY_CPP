#include "loop.h"
#include <whycpp/application_listener.h>
#include "clamp.h"
#include "logger.h"
#if __EMSCRIPTEN__
#include <emscripten.h>
void emscripten_Update(void* loop) {
  Loop* real_loop = reinterpret_cast<Loop*>(loop);
  real_loop->Update();
}
#endif

long SDL_GetTicksL() {
  return static_cast<long>(SDL_GetTicks());
}

void Loop::UpdateWithDelay() {
  long start = SDL_GetTicksL();

  cb(ctx, delta_time / 1000.0);

  long dt = SDL_GetTicksL() - start;
  auto lag = clamp(ms_per_frame - dt, 0L, ms_per_frame);
  if (lag > 0) SDL_Delay(static_cast<Uint32>(lag));
}
void Loop::Run() {
  now = SDL_GetTicksL();
  last = now;
  delta_time = 0;
  isRunning = true;
  RunLoop();
}
void Loop::Update() {
  last = now;
  now = SDL_GetTicksL();
  delta_time = now - last;
#if __EMSCRIPTEN__
  // In the browser it would be better to use requestAnimationFrame instead of SDL_DELAY
  cb(ctx, delta_time / 1000.0);
#else
  UpdateWithDelay();
#endif

  isRunning = !ctx.IsQuit();
  if (!isRunning) {
    listener->OnDispose(ctx);
#if __EMSCRIPTEN__
    emscripten_force_exit(0);
#endif
  }
}

void Loop::RunLoop() {
  listener->OnCreate(ctx);
#if __EMSCRIPTEN__
  // TODO: SDL2 has a bug so the SDL2 should be intialized inside loop
  emscripten_set_main_loop_arg(emscripten_Update, this, 0, 0);
#else
  while (isRunning) {
    Update();
  }
#endif
}
Loop::Loop(Loop::Callback& callback, Context& ctx, ApplicationListener* listener, long ms_per_frame)
    : cb(callback), ctx(ctx), listener(listener), ms_per_frame(ms_per_frame) {
  LOG_DEBUG("Loop created");
}
Loop::~Loop() {
  LOG_DEBUG("Loop destroyed");
}
