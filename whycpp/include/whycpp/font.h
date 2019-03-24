#ifndef WHYCPP_FONT_H
#define WHYCPP_FONT_H

#include <vector>
#include <cstdint>

/**
 * @addtogroup Text
 * @ingroup WHYCPP_PublicAPI
 *
 * @{
 */

struct Glyph {
  // TODO: why do we fix font size?
  const static int SIZE = 8;
  uint8_t data[SIZE];
};

/**
 * @class Font
 */
class Font {
 public:
  explicit Font(std::vector<Glyph> glyphs);
  uint8_t At(char ch, int row) const;
  int GetHeight() const;
  int GetWidth() const;
  int GetSpacing() const;
 private:
  int spacing = 1;
  int width = 5;
  int height = 7;
  std::vector<Glyph> glyphs;
};

/**
 * @}
 */

#endif //WHYCPP_FONT_H
