#pragma once

#include <whycpp/types.h>
#include <string>
#include <utility>

/**
 * @addtogroup Application
 * @{
 */

struct ApplicationConfig {
  const i32 width;
  const i32 height;
  const std::string name;
  const bool is_fullscreen;
  const i32 window_size_multiplier;
  const i32 ms_per_frame;
  const bool vsync;

  explicit ApplicationConfig(const i32 width = 256, const i32 height = 144, std::string name = "Application",
                             const bool is_fullscreen = false, i32 window_size_multiplier = 3, i32 ms_per_frame = 16,
                             bool vsync = true)
      : width(width),
        height(height),
        name(std::move(name)),
        is_fullscreen(is_fullscreen),
        window_size_multiplier(window_size_multiplier),
        ms_per_frame(ms_per_frame),
        vsync(vsync) {}

  i32 GetWindowWidth() const {
    return width * window_size_multiplier;
  }
  i32 GetWindowHeight() const {
    return height * window_size_multiplier;
  }
};

/** @} */
