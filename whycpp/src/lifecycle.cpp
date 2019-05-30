#include <whycpp/lifecycle.h>
#include "context.h"
#include "global_app_context.h"

void PauseApp() {
  GetContext().SetPaused(false);
}

void ResumeApp() {
  GetContext().SetPaused(true);
}

void ExitApp() {
  GetContext().SetQuit(true);
}