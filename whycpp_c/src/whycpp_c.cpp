//
// Created by k.leyfer on 27.03.2019.
//

#include <whycpp/whycpp.h>
#include <whycpp_c/whycpp_c.h>
#include "internal/application_listener_int.h"

void Run(ApplicationListener_t* listener, ApplicationConfig_t* config) {
  auto* applicationListener = new CallbackApplicationListener(listener);
  Run(applicationListener,
      ApplicationConfig(config->width, config->height, std::string(config->name), config->is_fullscreen != 0,
                        config->window_size_multiplier, config->ms_per_frame));
}
