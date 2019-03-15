#ifndef WHYCPP_APPLICATION_H
#define WHYCPP_APPLICATION_H

#include <string>
#include <memory>
#include <whycpp/application_config.h>

class ApplicationListener;
class VideoMemory;
class Context;
class SDLContext;
class Loop;

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
  explicit Application(ApplicationListener* listener, const ApplicationConfig &congig);
  virtual ~Application();

  void Run();
  void Update(Context& ctx, double delta_time);
  void RenderOrInit(); // it's lazy call
 private:
  std::unique_ptr<Loop> loop;
  std::unique_ptr<Context> context;
  std::unique_ptr<SDLContext> sdl_context;
  const std::unique_ptr<ApplicationListener> listener;
  const ApplicationConfig config;

  void HandleEvents(Context &ctx);
};

/** @} */

#endif //WHYCPP_APPLICATION_H
