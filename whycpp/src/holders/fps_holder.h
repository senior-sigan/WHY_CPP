#pragma once

#include <whycpp/application_config.h>
#include <whycpp/types.h>
#include "../average_window.h"
#include "../i_object.h"

class FpsHolder: public IObject {
  AverageWindow<double> deltasHistory_;

 public:
  explicit FpsHolder(const ApplicationConfig& config);

  i32 GetFPS() const;
  void SetRealDeltaTime(double delta);

  ~FpsHolder() override;
};
