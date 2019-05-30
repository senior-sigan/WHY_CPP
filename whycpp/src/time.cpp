#include <whycpp/time.h>
#include "global_app_context.h"

double GetTime() {
  return GetContext().GetTime();
}

double GetDelta() {
  return GetContext().GetDelta();
}

int GetFPS() {
  return GetContext().GetFPS();
}