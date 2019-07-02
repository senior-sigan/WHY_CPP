#include <whycpp/font.h>
#include <whycpp/types.h>
#include <utility>

uint8_t Font::At(char ch, i32 row) const {
  auto i = static_cast<u64>(ch);
  return glyphs.at(i).data[row];
}
i32 Font::GetHeight() const {
  return height;
}
i32 Font::GetWidth() const {
  return width;
}
i32 Font::GetSpacing() const {
  return spacing;
}
Font::Font(std::vector<Glyph> glyphs) : glyphs(std::move(glyphs)) {}
