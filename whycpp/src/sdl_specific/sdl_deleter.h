#pragma once

struct SDL_Renderer;
struct SDL_Window;
struct SDL_Texture;

struct sdl_deleter {
  void operator()(SDL_Window *) const;
  void operator()(SDL_Renderer *) const;
  void operator()(SDL_Texture *) const;
};
