#pragma once

#include <whycpp/types.h>
#include <cstdint>
#include <vector>

/**
 * @addtogroup Text
 * @ingroup WHYCPP_PublicAPI
 *
 * @{
 */

struct Glyph {
  static const i32 SIZE = 8;  // TODO: why do we fix font size?
  uint8_t data[SIZE];
};

/**
 * @class Font
 */
class Font {
 public:
  explicit Font(std::vector<Glyph> glyphs);
  uint8_t At(char ch, i32 row) const;
  i32 GetHeight() const;
  i32 GetWidth() const;
  i32 GetSpacing() const;

 private:
  i32 spacing = 1;
  i32 width = 5;
  i32 height = 7;
  std::vector<Glyph> glyphs;
};

/**
 * @}
 */
