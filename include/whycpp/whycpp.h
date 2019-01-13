#ifndef WHYCPP_WHYCPP_H
#define WHYCPP_WHYCPP_H

#include <whycpp/application_listener.h>

template<typename Listener>
void RunApp() {
  Listener l;
  Run(&l);
}

void Run(ApplicationListener *listener);

#endif //WHYCPP_WHYCPP_H
