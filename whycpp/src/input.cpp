#include "context.h"

bool IsPressed(const Context &ctx, const Button& btn) {
  return ctx.IsButtonPressed(btn);
}

bool IsClicked(const Context &ctx, const Button& btn) {
  return ctx.IsButtonReleased(btn);
}

void GetMouse(const Context &ctx, int& x, int& y) {
  x = ctx.mousePosX;
  y = ctx.mousePosY;
}