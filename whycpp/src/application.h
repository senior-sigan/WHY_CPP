#pragma once

#include <whycpp/application_config.h>
#include <memory>

class ApplicationListener;
class Context;

/**
 * @defgroup Internals WHYCPP secret internal implementation details
 * @brief Documentation useful when developing or debugging WHYCPP itself. Usual user should not use it.
 *
 */

/**
 * @defgroup ApplicationInternals Application
 * @ingroup Internals
 *
 * @{
 */

/**
 * @class Application
 */
class Application {
 public:
  explicit Application(ApplicationListener* listener, const ApplicationConfig& congig);
  virtual ~Application();

  void Run();
 private:
  // please, keep tis order, it's important for the object destruction order
  // Destuction order: [listener, loop, context, sdl context]
  const std::unique_ptr<Context> context;
  const std::unique_ptr<ApplicationListener> listener;
  const ApplicationConfig config;
};

/** @} */
