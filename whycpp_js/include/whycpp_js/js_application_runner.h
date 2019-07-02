#pragma once

#include <memory>
#include <vector>

class JsRegistrator;

class JsApplicationRunner {
  const char* root_path_;
  std::vector<std::unique_ptr<JsRegistrator>> registrators_{};

 public:
  explicit JsApplicationRunner(const char* root_path);
  virtual ~JsApplicationRunner();
  /**
   * A method to add Js-C++ custom bindings.
   * Registrator object will be destroyed by this class.
   * @param registrator
   */
  void AddRegistrator(JsRegistrator* registrator);
  /**
   * Run js-based application.
   * This call will block main thread.
   */
  void Execute();
};
