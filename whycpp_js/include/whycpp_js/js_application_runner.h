#ifndef WHYCPP_ROOT_WHYCPP_JS_SRC_JS_APPLICATION_RUNNER_H_
#define WHYCPP_ROOT_WHYCPP_JS_SRC_JS_APPLICATION_RUNNER_H_

class JsApplicationRunner {
  const char* root_path_;
 public:
  explicit JsApplicationRunner(const char* root_path);

  void Execute();
};

#endif //WHYCPP_ROOT_WHYCPP_JS_SRC_JS_APPLICATION_RUNNER_H_
