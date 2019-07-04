#pragma once

#include "../loop/i_inputs_handler.h"
class Context;
class ApplicationListener;

class SDLInputsHandler: public IInputsHandler {
  Context& ctx;
  ApplicationListener* listener_;

 public:
  SDLInputsHandler(Context& ctx, ApplicationListener* listener);
  void HandleEvents() override;
};
