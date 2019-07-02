#pragma once

class Context;
class ApplicationListener;

class InputsHandler {
  ApplicationListener* listener_;

 public:
  explicit InputsHandler(ApplicationListener* listener);
  void HandleEvents(Context& ctx);
};
