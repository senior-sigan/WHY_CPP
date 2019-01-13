#ifndef WHYCPP_WHYCPP_H
#define WHYCPP_WHYCPP_H

#include <whycpp/application_listener.h>
#include "application_config.h"

template<typename Listener>
void RunApp(const ApplicationConfig &config = {256, 144, "Application"}) {
  Listener l;
  Run(&l, config);
}

void Run(ApplicationListener *listener, const ApplicationConfig &config = {256, 144, "Application"});

#endif //WHYCPP_WHYCPP_H
