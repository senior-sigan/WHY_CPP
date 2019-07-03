#pragma once

#include <whycpp/buttons.h>
#include <whycpp/types.h>
#include <vector>
#include "../i_object.h"

class KeyboardHolder : public IObject {
  std::vector<bool> buttons_;
  std::vector<bool> clicked_;

 public:
  KeyboardHolder();

  bool IsButtonPressed(const Button &btn) const;
  bool IsButtonReleased(const Button &btn) const;

  void KeyUp(u32 code);
  void KeyDown(u32 code);
  void ResetKeys();

  ~KeyboardHolder() override;
};
