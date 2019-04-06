#ifndef WHYCPP_ROOT_PALETTE_H
#define WHYCPP_ROOT_PALETTE_H

#include "color.h"

#define TO_RAW(R, G, B, A) ((((((A << 8u) + B) << 8u) + G) << 8u) + R)

#define PALETTE_LEN 16

const RGBA_t PALETTE[PALETTE_LEN] = {
    TO_RAW(0, 0, 0, 255),
    TO_RAW(29, 43, 83, 255),
    TO_RAW(126, 37, 83, 255),
    TO_RAW(0, 135, 81, 255),
    TO_RAW(171, 82, 54, 255),
    TO_RAW(95, 87, 79, 255),
    TO_RAW(194, 195, 199, 255),
    TO_RAW(255, 241, 232, 255),
    TO_RAW(255, 0, 77, 255),
    TO_RAW(255, 163, 0, 255),
    TO_RAW(255, 240, 36, 255),
    TO_RAW(0, 231, 86, 255),
    TO_RAW(41, 173, 255, 255),
    TO_RAW(131, 118, 156, 255),
    TO_RAW(255, 119, 168, 255),
    TO_RAW(255, 204, 170, 255)
};

#endif  // WHYCPP_ROOT_PALETTE_H
