#pragma once

#include "../i_object.h"
class LifecycleHolder: public IObject {
  bool quit_ = false;
  bool paused_ = false;
 public:
  bool IsQuit() const;
  void SetQuit(bool quit);
  bool IsPaused() const;
  void SetPaused(bool paused);

  ~LifecycleHolder() override;
};


