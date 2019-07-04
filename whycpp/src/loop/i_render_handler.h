#pragma once
#include "../i_object.h"

class IRenderHandler : public IObject {
 public:
  virtual void Render() = 0;
  virtual ~IRenderHandler() = default;
};
