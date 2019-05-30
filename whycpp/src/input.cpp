#include "context.h"
#include "global_app_context.h"

bool IsPressed(const Button& btn) {
  return GetContext().IsButtonPressed(btn);
}

bool IsClicked(const Button& btn) {
  return GetContext().IsButtonReleased(btn);
}

void GetMouse(int& x, int& y) {
  x = GetContext().mousePosX;
  y = GetContext().mousePosY;
}
