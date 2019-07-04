#pragma once
#include "../i_object.h"

class IInputsHandler : public IObject {
 public:
  virtual void HandleEvents() = 0;
  ~IInputsHandler() override = default;
};
