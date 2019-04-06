#include <whycpp/lifecycle.h>
#include <whycpp_c/lifecycle.h>

#include "internal/global_context_int.h"

void PauseApp_C() {
  PauseApp(*GetContext_C());
}

void ResumeApp_C() {
  ResumeApp(*GetContext_C());
}

void ExitApp_C() {
  ExitApp(*GetContext_C());
}
