#ifndef WHYCPP_APPLICATION_H
#define WHYCPP_APPLICATION_H

#include <string>
#include <memory>
#include "sdl_deleter.h"

class ApplicationListener;
class VideoMemory;
class SDLTexture;
struct ApplicationConfig;
class Context;
struct SDL_Renderer;
struct SDL_Window;

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
  std::unique_ptr<SDL_Renderer, sdl_deleter> ren;
  std::unique_ptr<SDL_Window, sdl_deleter> win;
  std::unique_ptr<SDLTexture> texture;
  std::unique_ptr<VideoMemory> vram;
  const std::unique_ptr<ApplicationListener> listener;

  void Render();

  void HandleEvents(Context &ctx);
};

/** @} */

#endif //WHYCPP_APPLICATION_H
