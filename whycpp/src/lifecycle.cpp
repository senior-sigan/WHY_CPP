#include <whycpp/lifecycle.h>
#include "context.h"

void PauseApp(Context &context) {
  context.SetPaused(false);
}

void ResumeApp(Context &context) {
  context.SetPaused(true);
}

void ExitApp(Context &context) {
  context.SetQuit(true);
}