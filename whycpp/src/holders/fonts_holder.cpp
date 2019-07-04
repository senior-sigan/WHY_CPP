#include "fonts_holder.h"
#include <whycpp/font.h>
#include "../default_font.h"

Font* FontsHolder::GetFont() const {
  return font_.get();
}
void FontsHolder::SetFont(Font* font) {
  font_ = std::unique_ptr<Font>(font);
}
FontsHolder::FontsHolder() {
  font_ = std::unique_ptr<Font>(BuildDefaultFont());
}
FontsHolder::~FontsHolder() = default;
