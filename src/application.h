#ifndef WHYCPP_APPLICATION_H
#define WHYCPP_APPLICATION_H

#include <string>
#include <SDL2/SDL_video.h>
#include <SDL2/SDL_render.h>

class ApplicationListener;
class VideoMemory;
class SDLTexture;
struct ApplicationConfig;

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

  void Render();

  void HandleEvents();
};

#endif //WHYCPP_APPLICATION_H
