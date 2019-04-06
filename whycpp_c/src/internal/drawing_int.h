#ifndef WHYCPP_ROOT_DRAWING_INT_H
#define WHYCPP_ROOT_DRAWING_INT_H

#include <whycpp/color.h>

typedef union {
    struct RGBA rgba;
    uint32_t raw;
} RGBA_conv;

RGBA_t to_C(const RGBA &color);

RGBA to_Cpp(RGBA_t color);

#endif //WHYCPP_ROOT_DRAWING_INT_H
