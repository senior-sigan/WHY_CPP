#include <algorithm>
#include <cmath>
#include <whycpp/color.h>
#include <SDL2/SDL_render.h>
#include "sdl_texture.h"
#include "logger.h"
#include "video_memory.h"

SDLTexture::SDLTexture(const std::unique_ptr<SDL_Renderer, sdl_deleter>& ren, const VideoMemory &vram) : ren(ren), vram(vram) {
  auto buf_size = vram.GetWidth() * vram.GetHeight() * 4;
  // TODO: buf_size should be > 0. Maybe throw an exception?
  buffer = std::unique_ptr<uint8_t[]>(new uint8_t[buf_size]);
  tex = std::unique_ptr<SDL_Texture, sdl_deleter>(SDL_CreateTexture(ren.get(),
                                                                    SDL_PIXELFORMAT_ABGR8888,
                                                                    SDL_TEXTUREACCESS_STREAMING,
                                                                    vram.GetWidth(),
                                                                    vram.GetHeight()), sdl_deleter());
  if (!tex) {
    logSDLError("SDL_CreateTexture");
  }
}
SDLTexture::~SDLTexture() = default;
void SDLTexture::Render() {
  Draw();
  SDL_UpdateTexture(tex.get(), nullptr, buffer.get(), vram.GetWidth() * 4);
  auto dst = CalcSizes();
  SDL_RenderCopy(ren.get(), tex.get(), nullptr, &dst);
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
  SDL_QueryTexture(tex.get(), nullptr, nullptr, &dst.w, &dst.h);

  int sw, sh;
  SDL_GetRendererOutputSize(ren.get(), &sw, &sh);

  float rw = static_cast<float>(sw) / dst.w;
  float rh = static_cast<float>(sh) / dst.h;
  int r = static_cast<int>(std::floor(std::min(rw, rh)));

  dst.w *= r;
  dst.h *= r;

  return dst;
}
