#pragma once

#include <whycpp/types.h>
#include <memory>
#include <vector>
#include "../i_object.h"
#include "../sprite.h"

class SpritesHolder : public IObject {
  std::vector<std::unique_ptr<Sprite>> sprites_;

 public:
  i32 AppendSprite(Sprite *sprite);
  Sprite *GetSprite(i32 index) const;
  ~SpritesHolder() override;
};
