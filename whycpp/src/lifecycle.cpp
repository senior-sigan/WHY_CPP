#include <whycpp/lifecycle.h>
#include "context.h"
#include "holders/lifecycle_holder.h"

void PauseApp(Context &context) {
  context.Get<LifecycleHolder>()->SetPaused(false);
}

void ResumeApp(Context &context) {
  context.Get<LifecycleHolder>()->SetPaused(true);
}

void ExitApp(Context &context) {
  context.Get<LifecycleHolder>()->SetQuit(true);
}
