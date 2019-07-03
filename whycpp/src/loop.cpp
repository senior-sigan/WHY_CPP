#include "loop.h"
#include <whycpp/application_listener.h>
#include <cstdint>
#include "context.h"
#include "holders/fps_holder.h"
#include "holders/lifecycle_holder.h"
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
  while (lag >= ms_per_frame) {
    inputs(ctx, 0);
    update(ctx, ms_per_frame / 1000.0);
    lag -= ms_per_frame;
  }
  render(ctx, static_cast<double>(lag) / ms_per_frame);
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
  lag += delta_time;
  if (delta_time > 0) {
    ctx.Get<FpsHolder>()->SetRealDeltaTime(1000.0 / delta_time);
  }

  UpdateWithDelay();

  isRunning = !ctx.Get<LifecycleHolder>()->IsQuit();
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
Loop::Loop(Callback& update, Callback& render, Callback& inputs, Context& ctx, ApplicationListener* listener,
           i64 ms_per_frame)
    : update(update), render(render), inputs(inputs), ctx(ctx), listener(listener), ms_per_frame(ms_per_frame) {
  LOG_DEBUG("Loop created");
}
Loop::~Loop() {
  LOG_DEBUG("Loop destroyed");
}
