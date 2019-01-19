#ifndef WHYCPP_APPLICATION_H
#define WHYCPP_APPLICATION_H

#include <string>

class ApplicationListener;
class VideoMemory;
class SDLTexture;
struct ApplicationConfig;
class Context;
struct SDL_Renderer;
struct SDL_Window;

class Application {
 public:
  explicit Application(ApplicationListener *listener, const ApplicationConfig& congig);
  virtual ~Application();

  void Run();
 private:
  SDL_Renderer *ren;
  SDL_Window *win;
  VideoMemory *vram;
  SDLTexture *texture;
  ApplicationListener *const listener;

  bool quit = false;
  bool paused = false;

  void Render();

  void HandleEvents(Context &ctx);
};

#endif //WHYCPP_APPLICATION_H
