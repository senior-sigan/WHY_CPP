#ifndef WHYCPP_SDL_DELETER_H
#define WHYCPP_SDL_DELETER_H

struct SDL_Renderer;
struct SDL_Window;
struct SDL_Texture;

struct sdl_deleter {
  void operator()(SDL_Window *) const;
  void operator()(SDL_Renderer *) const;
  void operator()(SDL_Texture *) const;
};

#endif  // WHYCPP_SDL_DELETER_H
