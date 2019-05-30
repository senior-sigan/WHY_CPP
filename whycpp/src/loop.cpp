#include "loop.h"
#include <whycpp/application_listener.h>
#include <cstdint>
#include "global_app_context.h"
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
    inputs(0);
    update(ms_per_frame / 1000.0);
    lag -= ms_per_frame;
  }
  render(static_cast<double>(lag) / ms_per_frame);
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
    listener->OnCreate();
    first_start_ = false;
  }
  last = now;
  now = GetTicks();
  delta_time = now - last;
  lag += delta_time;
  if (delta_time > 0) {
    GetContext().SetRealDeltaTime(1000.0 / delta_time);
  }

  UpdateWithDelay();

  isRunning = !GetContext().IsQuit();
  if (!isRunning) {
    first_start_ = true;
    listener->OnDispose();
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
Loop::Loop(Callback& update, Callback& render, Callback& inputs, ApplicationListener* listener, long ms_per_frame)
    : update(update), render(render), inputs(inputs), listener(listener), ms_per_frame(ms_per_frame) {
  LOG_DEBUG("Loop created");
}
Loop::~Loop() {
  LOG_DEBUG("Loop destroyed");
}
