#ifndef WHYCPP_LOGGER_H
#define WHYCPP_LOGGER_H

#include <iostream>
#include <SDL2/SDL_error.h>

void logSDLError(const std::string &msg) {
  std::cout << msg << " error: " << SDL_GetError() << std::endl;
}

#endif //WHYCPP_LOGGER_H
