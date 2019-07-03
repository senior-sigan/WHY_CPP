#include "lifecycle_holder.h"

bool LifecycleHolder::IsQuit() const {
  return quit_;
}
void LifecycleHolder::SetQuit(bool quit) {
  quit_ = quit;
}
bool LifecycleHolder::IsPaused() const {
  return paused_;
}
void LifecycleHolder::SetPaused(bool paused) {
  paused_ = paused;
}
LifecycleHolder::~LifecycleHolder()= default;
