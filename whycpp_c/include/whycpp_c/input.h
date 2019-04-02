#ifndef WHYCPP_C_INPUT_H
#define WHYCPP_C_INPUT_H

#include <stdbool.h>
#include "buttons.h"

bool IsPressed_C(Button_t btn);

bool IsClicked_C(Button_t btn);

void GetMouse_C(int* x, int* y);

#endif //WHYCPP_C_INPUT_H
