#pragma once

#include <memory>
#include "../i_object.h"

class Font;

class FontsHolder : public IObject {
  std::unique_ptr<Font> font_;

 public:
  FontsHolder();
  Font *GetFont() const;
  void SetFont(Font *font);
  ~FontsHolder() override;
};
