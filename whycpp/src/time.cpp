#include <whycpp/time.h>
#include "context.h"
#include "holders/fps_holder.h"
#include "holders/time_holder.h"

double GetTime(const Context& ctx) {
  return ctx.container->Get<TimeHolder>()->GetTime();
}

double GetDelta(const Context& ctx) {
  return ctx.container->Get<TimeHolder>()->GetDelta();
}

i32 GetFPS(const Context& ctx) {
  return ctx.container->Get<FpsHolder>()->GetFPS();
}
