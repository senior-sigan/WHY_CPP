#ifndef WHYCPP_LOOP_H
#define WHYCPP_LOOP_H

#include <SDL2/SDL_timer.h>
#include <functional>
#include "context.h"

class ApplicationListener;

class Loop {
 public:
  typedef std::function<void(Context&, double)> Callback;

 private:
  Uint64 now = 0;
  Uint64 last = 0;
  double delta_time = 0.0;
  bool isRunning = true;

  Callback cb;
  Context& ctx;
  ApplicationListener* listener;

  void RunLoop();

 public:
  explicit Loop(Callback& callback, Context& ctx, ApplicationListener* listener);
  virtual ~Loop();

  void Run();

  void Update(); // DO NOT CALL IT
};

#endif  // WHYCPP_LOOP_H
