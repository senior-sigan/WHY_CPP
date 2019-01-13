#ifndef WHYCPP_DRAWING_H
#define WHYCPP_DRAWING_H

#include <cstdint>
#include <whycpp/context.h>
#include <whycpp/color.h>

int GetDisplayWidth(const Context &ctx);
int GetDisplayHeight(const Context &ctx);

void SetPixel(Context &ctx, int x, int y, const RGBA &color);
const RGBA GetPixel(const Context &ctx, int x, int y);

#endif //WHYCPP_DRAWING_H
