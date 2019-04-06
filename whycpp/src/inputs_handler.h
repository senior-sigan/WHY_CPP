#ifndef WHYCPP_ROOT_WHYCPP_SRC_INPUTS_HANDLER_H_
#define WHYCPP_ROOT_WHYCPP_SRC_INPUTS_HANDLER_H_

class Context;
class ApplicationListener;

class InputsHandler {
  ApplicationListener* listener_;
 public:
  explicit InputsHandler(ApplicationListener* listener);
  void HandleEvents(Context& ctx);
};



#endif  // WHYCPP_ROOT_WHYCPP_SRC_INPUTS_HANDLER_H_
