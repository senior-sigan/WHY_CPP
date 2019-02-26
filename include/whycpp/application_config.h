#ifndef WHYCPP_CONFIG_H
#define WHYCPP_CONFIG_H

#include <string>

/**
 * @addtogroup Application
 * @{
 */

struct ApplicationConfig {
  const int width = 256;
  const int height = 144;
  const std::string name = "Application";
  const bool is_fullscreen = false;
  const int window_width = width * 3;
  const int window_height = height * 3;
};

/** @} */

#endif //WHYCPP_CONFIG_H
