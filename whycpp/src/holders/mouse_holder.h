#pragma once

#include <whycpp/types.h>
#include "../i_object.h"

class MouseHolder : public IObject {
 public:
  i32 mousePosX = 0;
  i32 mousePosY = 0;
  ~MouseHolder() override;
};
