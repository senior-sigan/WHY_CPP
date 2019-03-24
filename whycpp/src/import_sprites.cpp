#include <lodepng/picopng.h>
#include <whycpp/color.h>
#include <whycpp/import_sprites.h>
#include <fstream>
#include <memory>
#include <vector>
#include "context.h"
#include "logger.h"
#include "video_memory.h"

using namespace std;

int ImportSprite(Context &context, const std::string &filename) {
  ifstream file(filename.c_str(), ios::in | ios::binary | ios::ate);

  std::streamsize size = 0;
  if (file.seekg(0, std::ios::end).good()) size = file.tellg();
  if (file.seekg(0, std::ios::beg).good()) size -= file.tellg();

  vector<unsigned char> buffer;
  if (size > 0) {
    buffer.resize(static_cast<unsigned long>(size));
    file.read(reinterpret_cast<char *>(&buffer[0]), size);
    LogInfo("Imported file '%s' of size=%d kB", filename.c_str(), size/1024);
  } else {
    buffer.clear();
    LogError("Cannot import file '%s'", filename.c_str());
    return -1;
  }

  vector<unsigned char> image;
  unsigned long w, h;
  int error = decodePNG(image, w, h, buffer.empty() ? nullptr : &buffer[0], buffer.size());
  if (error != 0) {
    LogError("Cannot decode png file '%s' error: %d", filename.c_str(), error);
  }
  if (image.size() > 4) {
    LogDebug("PNG '%s' width=%d height=%d", filename.c_str(), w, h);
  }

  auto sprite = new VideoMemory(static_cast<int>(w), static_cast<int>(h));
  for (int y = 0; y < sprite->GetHeight(); y++) {
    for (int x = 0; x < sprite->GetWidth(); x++) {
      auto i = 4 * (w * static_cast<unsigned long>(y) + static_cast<unsigned long>(x));
      sprite->Set(x, y, {image[i], image[i + 1], image[i + 2], image[i + 3]});
    }
  }

  return context.AppendSprite(sprite);
}
