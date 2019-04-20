#ifndef WHYCPP_APPLICATION_H
#define WHYCPP_APPLICATION_H

#include <whycpp/application_config.h>
#include <memory>
#include <string>

class ApplicationListener;
class VideoMemory;
class Context;
class SDLContext;
class Loop;
class InputsHandler;

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
  void Update(Context& ctx, double delta_time);
  void RenderOrInit();  // it's lazy call
 private:
  // please, keep tis order, it's important for the object destruction order
  // Destuction order: [listener, loop, context, sdl context]
  std::unique_ptr<SDLContext> sdl_context;
  std::unique_ptr<Context> context;
  std::unique_ptr<Loop> loop;
  std::unique_ptr<InputsHandler> input_handler_;
  const std::unique_ptr<ApplicationListener> listener;
  const ApplicationConfig config;
};

/** @} */

#endif  // WHYCPP_APPLICATION_H
