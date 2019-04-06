#ifndef WHYCPP_C_APPLICATION_LISTENER_H
#define WHYCPP_C_APPLICATION_LISTENER_H

#include <whycpp/c_api.h>

typedef void (*Callback)();

typedef struct ApplicationListener_t_ {
  Callback onCreate;
  Callback onDispose;
  Callback onPause;
  Callback onResume;
  Callback onRender;
} ApplicationListener_t;

#endif  // WHYCPP_C_APPLICATION_LISTENER_H
