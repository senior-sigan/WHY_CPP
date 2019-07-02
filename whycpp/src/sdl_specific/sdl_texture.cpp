#include "sdl_texture.h"
#include <SDL_render.h>
#include <whycpp/color.h>
#include <whycpp/types.h>
#include <algorithm>
#include <cmath>
#include "../logger.h"
#include "../video_memory.h"

SDLTexture::SDLTexture(SDL_Renderer* ren, VideoMemory* vram) : ren(ren), vram(vram) {
  tex = std::unique_ptr<SDL_Texture, sdl_deleter>(
      SDL_CreateTexture(ren, SDL_PIXELFORMAT_ABGR8888, SDL_TEXTUREACCESS_STREAMING, vram->GetWidth(),
                        vram->GetHeight()),
      sdl_deleter());
  if (!tex) {
    LogSDLError("SDL_CreateTexture");
  }
}
SDLTexture::~SDLTexture() = default;
void SDLTexture::Render() {
  SDL_UpdateTexture(tex.get(), nullptr, vram->GetBuffer(), vram->GetWidth() * 4);
  auto dst = CalcSizes();
  vram->SetScreenHeight(dst.h);
  vram->SetScreenWidth(dst.w);
  SDL_RenderCopy(ren, tex.get(), nullptr, &dst);
}
SDL_Rect SDLTexture::CalcSizes() {
  SDL_Rect dst = {0, 0, 0, 0};
  SDL_QueryTexture(tex.get(), nullptr, nullptr, &dst.w, &dst.h);

  i32 sw, sh;
  SDL_GetRendererOutputSize(ren, &sw, &sh);

  float rw = static_cast<float>(sw) / dst.w;
  float rh = static_cast<float>(sh) / dst.h;
  i32 r = static_cast<int>(std::floor(std::min(rw, rh)));

  dst.w *= r;
  dst.h *= r;

  return dst;
}
