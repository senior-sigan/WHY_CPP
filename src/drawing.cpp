#include <whycpp/drawing.h>
#include "context_impl.h"

int GetDisplayWidth(const Context &ctx) {
  return ctx.GetVRAM().GetWidth();
}

int GetDisplayHeight(const Context &ctx) {
  return ctx.GetVRAM().GetHeight();
}
void SetPixel(Context &ctx, int x, int y, const RGBA &color) {
  ctx.GetVRAM().Set(x, y, color);
}
const RGBA GetPixel(const Context &ctx, int x, int y) {
  return ctx.GetVRAM().Get(x, y);
}
