#include <utility>

#include <whycpp/font.h>

uint8_t Font::At(char ch, int row) const {
  auto i = static_cast<unsigned long>(ch);
  return glyphs.at(i).data[row];
}
int Font::GetHeight() const {
  return height;
}
int Font::GetWidth() const {
  return width;
}
int Font::GetSpacing() const {
  return spacing;
}
Font::Font(std::vector<Glyph> glyphs): glyphs(std::move(glyphs)) {}
