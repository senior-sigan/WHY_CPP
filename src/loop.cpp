#include "loop.h"
#include <whycpp/application_listener.h>
#if __EMSCRIPTEN__
#include <emscripten.h>
void emscripten_Update(void* loop) {
  Loop* real_loop = reinterpret_cast<Loop*>(loop);
  real_loop->Update();
}
#endif
#include <iostream>

void Loop::Run() {
  now = SDL_GetPerformanceCounter();
  last = now;
  delta_time = 0.0;
  isRunning = true;
  RunLoop();
}
void Loop::Update() {
  last = now;
  now = SDL_GetPerformanceCounter();
  delta_time = ((now - last) * 1000) / static_cast<double>(SDL_GetPerformanceFrequency());
  delta_time /= 1000.0;  // convert to seconds

  cb(ctx, delta_time);
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
Loop::Loop(Loop::Callback & callback, Context& ctx, ApplicationListener* listener) : cb(callback), ctx(ctx), listener(listener) {
  std::cout << "[DEBUG] Loop created" << std::endl;
}
Loop::~Loop(){
  std::cout << "[DEBUG] Loop destroyed" << std::endl;
}
