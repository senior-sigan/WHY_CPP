//
// Created by k.leyfer on 28.03.2019.
//

#ifndef WHYCPP_ROOT_IMPORT_SPRITES_H
#define WHYCPP_ROOT_IMPORT_SPRITES_H

#include <whycpp/c_api.h>

/**
 * Loads sprite into memory and return sprite id
 * @param filename
 * @return
 */
WHYCPP_C_API
int ImportSprite_C(const char* filename);

#endif  // WHYCPP_ROOT_IMPORT_SPRITES_H
