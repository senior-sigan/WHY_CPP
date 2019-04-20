#ifndef WHYCPP_IMPORT_SPRITES_H
#define WHYCPP_IMPORT_SPRITES_H

#include <string>

class Context;

/**
 * Loads sprite into memory and return sprite id
 * @param context
 * @param filename
 * @return
 */
int ImportSprite(Context &context, const std::string &filename);

#endif  // WHYCPP_IMPORT_SPRITES_H
