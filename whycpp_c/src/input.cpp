#include <whycpp/input.h>
#include <whycpp_c/input.h>

#include "internal/global_context_int.h"

bool IsPressed_C(Button_t btn) {
  return IsPressed(*GetContext_C(), static_cast<Button>(btn));
}

bool IsClicked_C(Button_t btn) {
  return IsClicked(*GetContext_C(), static_cast<Button>(btn));
}

void GetMouse_C(int* x, int* y) {
  GetMouse(*GetContext_C(), *x, *y);
}
