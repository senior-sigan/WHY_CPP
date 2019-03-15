#ifndef WHYCPP_APPLICATION_H
#define WHYCPP_APPLICATION_H

#include <string>
#include <memory>

class ApplicationListener;
class VideoMemory;
struct ApplicationConfig;
class Context;
class SDLContext;

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
 private:
  std::unique_ptr<SDLContext> sdl_context;
  std::unique_ptr<VideoMemory> vram;
  const std::unique_ptr<ApplicationListener> listener;

  void HandleEvents(Context &ctx);
};

/** @} */

#endif //WHYCPP_APPLICATION_H
