#include <whycpp/lifecycle.h>
#include "context.h"
#include "holders/lifecycle_holder.h"

void PauseApp(Context &context) {
  context.container->Get<LifecycleHolder>()->SetPaused(false);
}

void ResumeApp(Context &context) {
  context.container->Get<LifecycleHolder>()->SetPaused(true);
}

void ExitApp(Context &context) {
  context.container->Get<LifecycleHolder>()->SetQuit(true);
}
