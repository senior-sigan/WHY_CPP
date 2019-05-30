#ifndef WHYCPP_LOOP_H
#define WHYCPP_LOOP_H

#include <functional>

class ApplicationListener;

class Loop {
 public:
  typedef std::function<void(double)> Callback;

 private:
  Callback update;
  Callback render;
  Callback inputs;
  ApplicationListener* listener;

  long now = 0;
  long last = 0;
  long delta_time = 0;
  bool isRunning = true;
  long ms_per_frame = 16;
  bool first_start_ = true;
  long lag = 0;

  void RunLoop();
  void UpdateWithDelay();

 public:
  explicit Loop(Callback& update, Callback& render, Callback& inputs, ApplicationListener* listener, long ms_per_frame = 16);
  virtual ~Loop();

  void Run();

  void Update();  // DO NOT CALL IT
};

#endif  // WHYCPP_LOOP_H
