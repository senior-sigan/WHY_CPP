#ifndef WHYCPP_LOOP_H
#define WHYCPP_LOOP_H

#include <SDL2/SDL_timer.h>
#include <functional>
#include "context.h"

class Loop {
 public:
  typedef std::function<void(Context&, double)> Callback;

 private:
  Uint64 now = 0;
  Uint64 last = 0;
  double delta_time = 0.0;
  Callback cb;
  Context& ctx;
  bool isRunning = true;

  void RunLoop();

 public:
  explicit Loop(Callback& callback, Context& ctx) : cb(callback), ctx(ctx) {}

  void Run();

  void Update(); // DO NOT CALL IT
};

#endif  // WHYCPP_LOOP_H
