#pragma once

#include "../i_object.h"
class TimeHolder : public IObject {
  double time_ = 0.0;
  double current_delta_ = 0.0;

 public:
  void Tick(double delta);
  double GetTime() const;
  double GetDelta() const;

  virtual ~TimeHolder();
};
