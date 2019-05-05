#include "loop.h"
#include <whycpp/application_listener.h>
#include <cstdint>
#include "int_utils.h"
#include "logger.h"
#include "timing.h"
#if __EMSCRIPTEN__
#include <emscripten.h>
void emscripten_Update(void* loop) {
  Loop* real_loop = reinterpret_cast<Loop*>(loop);
  real_loop->Update();
}
#endif

void Loop::UpdateWithDelay() {
  long start = GetTicks();

  cb(ctx, delta_time / 1000.0);
  if (ms_per_frame == 0)
    return;

  long dt = GetTicks() - start;
  auto lag = clamp(ms_per_frame - dt, 0L, ms_per_frame);
  if (lag > 0) {
    Delay(static_cast<uint32_t>(lag));
  }
}
void Loop::Run() {
  now = GetTicks();
  last = now;
  delta_time = 0;
  isRunning = true;
  RunLoop();
}
void Loop::Update() {
  if (first_start_) {
    listener->OnCreate(ctx);
    first_start_ = false;
  }
  last = now;
  now = GetTicks();
  delta_time = now - last;
#if __EMSCRIPTEN__
  // In the browser it would be better to use requestAnimationFrame instead of SDL_DELAY
  cb(ctx, delta_time / 1000.0);
#else
  UpdateWithDelay();
#endif

  isRunning = !ctx.IsQuit();
  if (!isRunning) {
    first_start_ = true;
    listener->OnDispose(ctx);
#if __EMSCRIPTEN__
    emscripten_force_exit(0);
#endif
  }
}

void Loop::RunLoop() {
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
