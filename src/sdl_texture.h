#ifndef WHYCPP_SDLTEXTURE_H
#define WHYCPP_SDLTEXTURE_H

#include <cstdint>

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
  explicit SDLTexture(SDL_Renderer *ren, const VideoMemory &vram);
  virtual ~SDLTexture();

  void Render();
 private:
  SDL_Renderer *ren;
  const VideoMemory& vram;
  uint8_t *buffer;
  SDL_Texture *tex;

  void Draw();
  SDL_Rect CalcSizes();
};

/** @} */

#endif //WHYCPP_SDLTEXTURE_H
