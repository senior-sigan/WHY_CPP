#include <whycpp/drawing.h>
#include <whycpp/text.h>
#include <whycpp/types.h>
#include "context.h"

void Print(Context &ctx, char ch, i32 x, i32 y, const RGBA &color, i32 size) {
  auto font = ctx.GetFont();
  for (uint8_t row = 0; row < Glyph::SIZE; row++) {
    for (uint8_t col = 0; col < 8; col++) {
      if (((font->At(ch, row) >> col) & 0x1) == 1) {
        for (i32 i = 0; i < size; i++) {
          for (i32 j = 0; j < size; j++) {
            SetPixel(ctx, x + col * size + i, y + row * size + j, color);
          }
        }
      }
    }
  }
}

void Print(Context &ctx, const std::string &str, i32 x, i32 y, const RGBA &color, i32 size, i32 spacing) {
  auto font = ctx.GetFont();
  // TODO: add \n, \t, \r and other escape symbols support
  i32 x_ = x;
  i32 y_ = y;

  for (char ch : str) {
    // TODO: it should be state machine, but .....
    if (ch == '\n') {
      y_ += (font->GetHeight() + font->GetSpacing() + spacing) * size;
      x_ = x;
      continue;
    } else if (ch == '\r') {
      x_ = x;
      continue;
    }

    Print(ctx, ch, x_, y_, color, size);
    x_ += (font->GetWidth() + font->GetSpacing()) * size;
  }
}
