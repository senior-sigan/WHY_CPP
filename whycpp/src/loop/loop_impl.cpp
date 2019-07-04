#include "loop_impl.h"
#include "../context.h"

LoopImpl::LoopImpl(Context& ctx, ApplicationListener* listener, i64 ms_per_frame)
    : ILoop(ctx, listener, ms_per_frame) {}

#if __EMSCRIPTEN__
#include <emscripten.h>
void emscripten_Update(void* loop) {
  auto real_loop = reinterpret_cast<LoopImpl*>(loop);
  real_loop->Update();
}

void LoopImpl::RunLoop() {
  emscripten_set_main_loop_arg(emscripten_Update, this, 0, 0);
}
void LoopImpl::StopLoop() {
  emscripten_force_exit(0);
}
#else

#include "../holders/lifecycle_holder.h"

void LoopImpl::RunLoop() {
  while (!ctx.Get<LifecycleHolder>()->IsQuit()) {
    Update();
  }
}
void LoopImpl::StopLoop() {
  // nothing to do
}
#endif
