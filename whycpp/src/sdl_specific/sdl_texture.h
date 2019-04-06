#ifndef WHYCPP_SDLTEXTURE_H
#define WHYCPP_SDLTEXTURE_H

#include <cstdint>
#include <memory>
#include "sdl_deleter.h"

class VideoMemory;
struct SDL_Renderer;
struct SDL_Texture;
struct SDL_Rect;

/**
 * @addtogroup DrawingInternals
 *
 * @{
 */

class SDLTexture {
 public:
  explicit SDLTexture(SDL_Renderer* ren, VideoMemory* vram);
  virtual ~SDLTexture();

  void Render();

 private:
  SDL_Renderer* ren;
  VideoMemory* vram;
  std::unique_ptr<uint8_t[]> buffer;
  std::unique_ptr<SDL_Texture, sdl_deleter> tex;

  void Draw();
  SDL_Rect CalcSizes();
};

/** @} */

#endif  // WHYCPP_SDLTEXTURE_H
