#include <whycpp/time.h>
#include "context.h"

double GetTime(const Context& ctx) {
  return ctx.GetTime();
}

double GetDelta(const Context& ctx) {
  return ctx.GetDelta();
}

i32 GetFPS(const Context& ctx) {
  return ctx.GetFPS();
}
