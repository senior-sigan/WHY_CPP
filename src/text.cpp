#include <whycpp/text.h>
#include <whycpp/drawing.h>
#include <iostream>
#include "context.h"

void Print(Context &ctx,
           char ch,
           int x,
           int y,
           const RGBA &color,
           int size
) {
  auto font = ctx.GetFont();
  for (uint8_t row = 0; row < Glyph::SIZE; row++) {
    for (uint8_t col = 0; col < 8; col++) {
      if (((font.At(ch, row) >> col) & 0x1) == 1) {
        for (int i = 0; i < size; i++) {
          for (int j = 0; j < size; j++) {
            SetPixel(ctx, x + col * size + i, y + row * size + j, color);
          }
        }
      }
    }
  }
}

void Print(Context &ctx,
           const std::string &str,
           int x,
           int y,
           const RGBA &color,
           int size,
           int spacing
) {
  auto font = ctx.GetFont();
// TODO: add \n, \t, \r and other escape symbols support
  int x_ = x;
  int y_ = y;

  for (char ch: str) {
    // TODO: it should be state machine, but .....
    if (ch == '\n') {
      y_ += (font.GetHeight() + font.GetSpacing() + spacing) * size;
      x_ = x;
      continue;
    } else if (ch == '\r') {
      x_ = x;
      continue;
    }

    if (x_ < GetDisplayWidth(ctx) - font.GetWidth() && x > 0) {
      Print(ctx, ch, x_, y_, color, size);
    } else {
      std::cout << "[WARN][Font#Print]: cannot print symbol '" << ch << "': out of screen." << std::endl;
    }
    x_ += (font.GetWidth() + font.GetSpacing()) * size;
  }
}
