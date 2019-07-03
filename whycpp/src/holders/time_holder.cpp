#include "time_holder.h"

void TimeHolder::Tick(double delta) {
  current_delta_ = delta;
  time_ += delta;
}
double TimeHolder::GetTime() const {
  return time_;
}
double TimeHolder::GetDelta() const {
  return current_delta_;
}
TimeHolder::~TimeHolder()= default;
