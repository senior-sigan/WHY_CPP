#include <whycpp/import_sprites.h>
#include <whycpp_c/import_sprites.h>
#include "internal/global_context_int.h"

int ImportSprite_C(const char* filename) {
  return ImportSprite(*GetContext_C(), std::string(filename));
}
