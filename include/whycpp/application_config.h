#include <utility>

#ifndef WHYCPP_CONFIG_H
#define WHYCPP_CONFIG_H

#include <string>

/**
 * @addtogroup Application
 * @{
 */

struct ApplicationConfig {
  const int width;
  const int height;
  const std::string name;
  const bool is_fullscreen;

  explicit ApplicationConfig(const int width = 256,
                    const int height = 144,
                    std::string name = "Application",
                    const bool is_fullscreen = false)
      : width(width), height(height), name(std::move(name)), is_fullscreen(is_fullscreen) {}

  int GetWindowWidth() const {
    return width * 3;
  }
  int GetWindowHeight() const {
    return height * 3;
  }
};

/** @} */

#endif //WHYCPP_CONFIG_H
