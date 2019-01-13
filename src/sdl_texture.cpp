#include "sdl_texture.h"
#include "logger.h"
#include <cmath>
#include <algorithm>
#include <whycpp/color.h>
#include "video_memory.h"

SDLTexture::SDLTexture(SDL_Renderer *ren, const VideoMemory &vram) : ren(ren), vram(vram) {
  buffer = new uint8_t[vram.GetWidth() * vram.GetHeight() * 4];
  tex = SDL_CreateTexture(ren,
                          SDL_PIXELFORMAT_ABGR8888,
                          SDL_TEXTUREACCESS_STREAMING,
                          vram.GetWidth(),
                          vram.GetHeight());
  if (tex == nullptr) {
    logSDLError("SDL_CreateTexture");
  }
}
SDLTexture::~SDLTexture() {
  SDL_DestroyTexture(tex);
  delete[] buffer;
}
void SDLTexture::Render() {
  Draw();
  SDL_UpdateTexture(tex, nullptr, buffer, vram.GetWidth() * 4);
  auto dst = CalcSizes();
  SDL_RenderCopy(ren, tex, nullptr, &dst);
}
void SDLTexture::Draw() {
  for (int x = 0; x < vram.GetWidth(); x++) {
    for (int y = 0; y < vram.GetHeight(); y++) {
      auto color = vram.Get(x, y);
      auto index = y * vram.GetWidth() + x;
      buffer[4 * index + 0] = color.red;
      buffer[4 * index + 1] = color.green;
      buffer[4 * index + 2] = color.blue;
      buffer[4 * index + 3] = color.alpha;
    }
  }
}
SDL_Rect SDLTexture::CalcSizes() {
  SDL_Rect dst = {0, 0, 0, 0};
  SDL_QueryTexture(tex, nullptr, nullptr, &dst.w, &dst.h);

  int sw, sh;
  SDL_GetRendererOutputSize(ren, &sw, &sh);

  float rw = static_cast<float>(sw) / dst.w;
  float rh = static_cast<float>(sh) / dst.h;
  int r = static_cast<int>(std::floor(std::min(rw, rh)));

  dst.w *= r;
  dst.h *= r;

  return dst;
}
