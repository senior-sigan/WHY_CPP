#ifndef WHYCPP_C_INPUT_H
#define WHYCPP_C_INPUT_H

#include <stdbool.h>
#include "buttons.h"
#include <whycpp/c_api.h>

WHYCPP_C_API
bool IsPressed_C(Button_t btn);

WHYCPP_C_API
bool IsClicked_C(Button_t btn);

WHYCPP_C_API
void GetMouse_C(int* x, int* y);

#endif  // WHYCPP_C_INPUT_H
