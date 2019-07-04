#include "fps_holder.h"

i32 FpsHolder::GetFPS() const {
  return static_cast<int>(deltasHistory_.Get());
}
void FpsHolder::SetRealDeltaTime(double delta) {
  deltasHistory_.Add(delta);
}
FpsHolder::FpsHolder(const ApplicationConfig& config)
    : deltasHistory_(static_cast<size_t>(500.0 / config.ms_per_frame)) {}
FpsHolder::~FpsHolder() {}
