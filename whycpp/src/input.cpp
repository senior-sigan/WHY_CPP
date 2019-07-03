#include "context.h"
#include "holders/keyboard_holder.h"
#include "holders/mouse_holder.h"

bool IsPressed(const Context& ctx, const Button& btn) {
  return ctx.container->Get<KeyboardHolder>()->IsButtonPressed(btn);
}

bool IsClicked(const Context& ctx, const Button& btn) {
  return ctx.container->Get<KeyboardHolder>()->IsButtonReleased(btn);
}

void GetMouse(const Context& ctx, int& x, int& y) {
  x = ctx.container->Get<MouseHolder>()->mousePosX;
  y = ctx.container->Get<MouseHolder>()->mousePosY;
}
