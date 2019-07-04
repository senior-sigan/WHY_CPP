#include "../context.h"
#include "../holders/keyboard_holder.h"
#include "../holders/mouse_holder.h"

bool IsPressed(const Context& ctx, const Button& btn) {
  return ctx.Get<KeyboardHolder>()->IsButtonPressed(btn);
}

bool IsClicked(const Context& ctx, const Button& btn) {
  return ctx.Get<KeyboardHolder>()->IsButtonReleased(btn);
}

void GetMouse(const Context& ctx, int& x, int& y) {
  x = ctx.Get<MouseHolder>()->mousePosX;
  y = ctx.Get<MouseHolder>()->mousePosY;
}
