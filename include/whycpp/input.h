#ifndef WHYCPP_INPUTS_H
#define WHYCPP_INPUTS_H

#include <whycpp/buttons.h>

class Context;

bool IsPressed(const Context &ctx, const Button& btn);
bool IsClicked(const Context &ctx, const Button& btn);

#endif //WHYCPP_INPUTS_H
