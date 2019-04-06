#ifndef WHYCPP_C_PALETTE_H
#define WHYCPP_C_PALETTE_H

#include "color.h"

#define TO_RAW(R, G, B, A) ((((((A << 8u) + B) << 8u) + G) << 8u) + R)

#define PALETTE_LEN 16u

extern const RGBA_t PALETTE[PALETTE_LEN];

#endif  // WHYCPP_C_PALETTE_H
