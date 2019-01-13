#include "logger.h"
#include <SDL2/SDL_error.h>
#include <iostream>

void logSDLError(const std::string &msg) {
  std::cout << msg << " error: " << SDL_GetError() << std::endl;
}
