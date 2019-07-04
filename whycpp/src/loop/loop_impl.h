#pragma once

#include "i_loop.h"

class LoopImpl : public ILoop {
#if __EMSCRIPTEN__
  friend void emscripten_Update(void* loop);
#endif
 public:
  LoopImpl(Context& ctx, ApplicationListener* listener, i64 ms_per_frame);
 private:
  void RunLoop() override;
  void StopLoop() override;
};
