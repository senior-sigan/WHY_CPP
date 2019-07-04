#include <lodepng/picopng.h>
#include <whycpp/color.h>
#include <whycpp/import_sprites.h>
#include <whycpp/types.h>
#include <fstream>
#include <memory>
#include <vector>
#include "context.h"
#include "holders/sprites_holder.h"
#include "logger.h"
#include "sprite.h"

i32 ImportSprite(Context &context, const std::string &filename) {
  std::ifstream file(filename.c_str(), std::ios::in | std::ios::binary | std::ios::ate);

  std::streamsize size = 0;
  if (file.seekg(0, std::ios::end).good()) size = file.tellg();
  if (file.seekg(0, std::ios::beg).good()) size -= file.tellg();

  std::vector<unsigned char> buffer;
  if (size > 0) {
    buffer.resize(static_cast<u64>(size));
    file.read(reinterpret_cast<char *>(&buffer[0]), size);
    LOG_DEBUG("Imported file '%s' of size=%d kB", filename.c_str(), size / 1024);
  } else {
    buffer.clear();
    LOG_ERROR("Cannot import file '%s'", filename.c_str());
    return -1;
  }

  std::vector<unsigned char> image;
  u64 w, h;
  i32 error = decodePNG(image, w, h, buffer.empty() ? nullptr : &buffer[0], buffer.size());
  if (error != 0) {
    LOG_ERROR("Cannot decode png file '%s' error: %d", filename.c_str(), error);
  }
  if (image.size() > 4) {
    LOG_DEBUG("PNG '%s' width=%d height=%d", filename.c_str(), w, h);
  }

  auto sprite = new Sprite(static_cast<int>(w), static_cast<int>(h));
  for (i32 y = 0; y < sprite->GetHeight(); y++) {
    for (i32 x = 0; x < sprite->GetWidth(); x++) {
      auto i = 4 * (w * static_cast<u64>(y) + static_cast<u64>(x));
      sprite->Set(x, y, {image[i], image[i + 1], image[i + 2], image[i + 3]});
    }
  }

  return context.Get<SpritesHolder>()->AppendSprite(sprite);
}
