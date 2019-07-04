#include "sprites_holder.h"

i32 SpritesHolder::AppendSprite(Sprite* sprite) {
  sprites_.push_back(std::unique_ptr<Sprite>(sprite));
  return static_cast<int>(sprites_.size() - 1);
}

Sprite* SpritesHolder::GetSprite(i32 index) const {
  return sprites_.at(static_cast<u64>(index)).get();
}

SpritesHolder::~SpritesHolder() = default;
