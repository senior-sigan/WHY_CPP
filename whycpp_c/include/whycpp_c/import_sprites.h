#pragma once

#include <whycpp/c_api.h>

/**
 * Loads sprite into memory and return sprite id
 * @param filename
 * @return
 */
WHYCPP_C_API
int ImportSprite_C(const char* filename);
