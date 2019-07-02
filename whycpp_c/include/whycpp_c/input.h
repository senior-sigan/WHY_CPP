#pragma once

#include <stdbool.h>
#include <whycpp/c_api.h>
#include "buttons.h"

WHYCPP_C_API
bool IsPressed_C(Button_t btn);

WHYCPP_C_API
bool IsClicked_C(Button_t btn);

WHYCPP_C_API
void GetMouse_C(int* x, int* y);
