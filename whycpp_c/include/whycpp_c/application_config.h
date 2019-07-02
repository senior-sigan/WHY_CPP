#pragma once

#include <whycpp/c_api.h>

typedef struct ApplicationConfig_t_ {
  int width;
  int height;
  const char* name;
  int is_fullscreen;
  int window_size_multiplier;
  long ms_per_frame;
} ApplicationConfig_t;
