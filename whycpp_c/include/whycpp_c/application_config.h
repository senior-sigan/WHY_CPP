//
// Created by k.leyfer on 27.03.2019.
//

#ifndef WHYCPP_C_APPLICATION_CONFIG_H
#define WHYCPP_C_APPLICATION_CONFIG_H

#include "c_api.h"

typedef struct ApplicationConfig_t_ {
  int width;
  int height;
  const char* name;
  int is_fullscreen;
  int window_size_multiplier;
  long ms_per_frame;
} ApplicationConfig_t;

#endif  // WHYCPP_C_APPLICATION_CONFIG_H
