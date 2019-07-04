#include "keyboard_holder.h"

void KeyboardHolder::KeyUp(const u32 code) {
  if (code >= KEY_NUM_KEYS) return;
  buttons_[code] = false;
  clicked_[code] = true;
}
void KeyboardHolder::KeyDown(const u32 code) {
  if (code >= KEY_NUM_KEYS) return;
  buttons_[code] = true;
  clicked_[code] = false;
}
void KeyboardHolder::ResetKeys() {
  for (u32 i = 0; i < KEY_NUM_KEYS; i++) {
    clicked_[i] = false;
  }
}

bool KeyboardHolder::IsButtonPressed(const Button& btn) const {
  if (static_cast<unsigned>(btn) >= buttons_.size()) return false;
  return buttons_.at(btn);
}
bool KeyboardHolder::IsButtonReleased(const Button& btn) const {
  if (static_cast<unsigned>(btn) >= buttons_.size()) return false;
  return clicked_.at(btn);
}
KeyboardHolder::KeyboardHolder() {
  buttons_.resize(Button::KEY_NUM_KEYS);
  clicked_.resize(Button::KEY_NUM_KEYS);
}
KeyboardHolder::~KeyboardHolder() = default;
