#ifndef WHYCPP_LOOP_H
#define WHYCPP_LOOP_H

#include <SDL_timer.h>
#include <functional>
#include "context.h"

class ApplicationListener;

class Loop {
 public:
  typedef std::function<void(Context&, double)> Callback;

 private:
  Callback cb;
  Context& ctx;
  ApplicationListener* listener;

  long now = 0;
  long last = 0;
  long delta_time = 0;
  bool isRunning = true;
  long ms_per_frame = 16;

  void RunLoop();
  void UpdateWithDelay();

 public:
  explicit Loop(Callback& callback, Context& ctx, ApplicationListener* listener, long ms_per_frame = 16);
  virtual ~Loop();

  void Run();

  void Update();  // DO NOT CALL IT
};

#endif  // WHYCPP_LOOP_H
