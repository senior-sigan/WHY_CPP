#pragma once
#include <whycpp/types.h>
#include "../i_object.h"

class Context;
class ApplicationListener;
class IInputsHandler;
class IRenderHandler;

class ILoop: public IObject {
 protected:
  Context& ctx;
  ApplicationListener* listener;
  IInputsHandler* inputs;
  IRenderHandler* renderer;

  i64 now = 0;
  i64 last = 0;
  i64 delta_time = 0;
  i64 ms_per_frame = 16;
  i64 lag = 0;

  virtual void RunLoop() = 0;
  virtual void StopLoop() = 0;

  void UpdateWithDelay();
  void Update();

 public:
  ILoop(Context& ctx, ApplicationListener* listener, i64 ms_per_frame = 16);

  void Run();
  ~ILoop() override;
};
