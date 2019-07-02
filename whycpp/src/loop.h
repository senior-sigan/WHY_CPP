#pragma once

#include <whycpp/types.h>
#include <functional>
#include "context.h"

class ApplicationListener;

class Loop {
 public:
  typedef std::function<void(Context&, double)> Callback;

 private:
  Callback update;
  Callback render;
  Callback inputs;
  Context& ctx;
  ApplicationListener* listener;

  i64 now = 0;
  i64 last = 0;
  i64 delta_time = 0;
  bool isRunning = true;
  i64 ms_per_frame = 16;
  bool first_start_ = true;
  i64 lag = 0;

  void RunLoop();
  void UpdateWithDelay();

 public:
  explicit Loop(Callback& update, Callback& render, Callback& inputs, Context& ctx, ApplicationListener* listener,
                i64 ms_per_frame = 16);
  virtual ~Loop();

  void Run();

  void Update();  // DO NOT CALL IT
};
