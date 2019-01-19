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
};

/** @} */

#endif //WHYCPP_CONFIG_H
