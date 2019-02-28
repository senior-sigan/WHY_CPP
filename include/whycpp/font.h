#ifndef WHYCPP_FONT_H
#define WHYCPP_FONT_H

#include <vector>

/**
 * @addtogroup Text
 * @ingroup WHYCPP_PublicAPI
 *
 * @{
 */

struct Glyph {
  // TODO: why do we fix font size?
  const static int SIZE = 8;
  int data[SIZE];
};

/**
 * @class Font
 */
class Font {
 public:
  explicit Font(const std::vector<Glyph> &glyphs);
  int At(char ch, int row) const;
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
