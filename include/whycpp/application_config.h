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
  const int window_size_multiplier;

  explicit ApplicationConfig(const int width = 256,
                    const int height = 144,
                    std::string name = "Application",
                    const bool is_fullscreen = false,
                    int window_size_multiplier = 3)
      : width(width), height(height), name(std::move(name)), is_fullscreen(is_fullscreen), window_size_multiplier(window_size_multiplier) {}

  int GetWindowWidth() const {
    return width * window_size_multiplier;
  }
  int GetWindowHeight() const {
    return height * window_size_multiplier;
  }
};

/** @} */

#endif //WHYCPP_CONFIG_H
