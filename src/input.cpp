#include "context_impl.h"

bool IsPressed(const Context &ctx, const Button& btn) {
  return ctx.IsButtonPressed(btn);
}

bool IsClicked(const Context &ctx, const Button& btn) {
  return ctx.IsButtonReleased(btn);
}