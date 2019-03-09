#include <iostream>
#include <fstream>
#include <whycpp/import_sprites.h>
#include <memory>
#include <vector>
#include <lodepng/picopng.h>
#include "video_memory.h"
#include <whycpp/color.h>
#include "context.h"

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
    cout << "Imported file '" << filename << "' of size " << size / 1024 << " Kb." << endl;
  } else {
    buffer.clear();
    cerr << "Cannot import file '" << filename << "'." << endl;
    return -1;
  }

  vector<unsigned char> image;
  unsigned long w, h;
  int error = decodePNG(image, w, h, buffer.empty() ? nullptr : &buffer[0], buffer.size());
  if (error != 0) {
    cout << "Cannot decode png file '" << filename << "' error: " << error << endl;
  }
  if (image.size() > 4) {
    cout << "PNG '" << filename << "' width: " << w << " height: " << h << endl;
  }

  VideoMemory sprite(static_cast<int>(w), static_cast<int>(h));
  for (int y = 0; y < sprite.GetHeight(); y++) {
    for (int x = 0; x < sprite.GetWidth(); x++) {
      auto i = 4*(w * static_cast<unsigned long>(y) + static_cast<unsigned long>(x));
      RGBA color{image[i], image[i + 1], image[i + 2], image[i + 3]};
      sprite.Set(x, y, color);
    }
  }

  return context.AppendSprite(sprite);
}
