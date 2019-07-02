#pragma once

#include <whycpp/types.h>
#include <string>

class Context;

/**
 * Loads sprite into memory and return sprite id
 * @param context
 * @param filename
 * @return
 */
i32 ImportSprite(Context &context, const std::string &filename);
