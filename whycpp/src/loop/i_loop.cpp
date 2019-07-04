#include "i_loop.h"
#include <whycpp/application_listener.h>
#include "../context.h"
#include "../holders/fps_holder.h"
#include "../holders/lifecycle_holder.h"
#include "../holders/time_holder.h"
#include "../timing.h"
#include "i_inputs_handler.h"
#include "i_render_handler.h"

void ILoop::UpdateWithDelay() {
  while (lag >= ms_per_frame) {
    inputs->HandleEvents();
    if (!ctx.Get<LifecycleHolder>()->IsPaused()) {
      ctx.Get<TimeHolder>()->Tick(ms_per_frame / 1000.0);
      listener->OnRender(ctx);
    }
    lag -= ms_per_frame;
  }
  renderer->Render();
}
void ILoop::Update() {
  last = now;
  now = GetTicks();
  delta_time = now - last;
  lag += delta_time;
  if (delta_time > 0) {
    ctx.Get<FpsHolder>()->SetRealDeltaTime(1000.0 / delta_time);
  }

  UpdateWithDelay();

  if (ctx.Get<LifecycleHolder>()->IsQuit()) {
    listener->OnDispose(ctx);
    StopLoop();
  }
}
void ILoop::Run() {
  now = GetTicks();
  last = now;
  delta_time = 0;

  listener->OnCreate(ctx);
  RunLoop();
}
ILoop::ILoop(Context &ctx, ApplicationListener *listener, i64 ms_per_frame)
    : ctx(ctx), listener(listener), ms_per_frame(ms_per_frame) {
  inputs = ctx.Get<IInputsHandler>();
  renderer = ctx.Get<IRenderHandler>();
  assert(inputs != nullptr);
  assert(renderer != nullptr);
  LOG_DEBUG("Loop created");
}
ILoop::~ILoop() {
  LOG_DEBUG("Loop destroyed");
}
