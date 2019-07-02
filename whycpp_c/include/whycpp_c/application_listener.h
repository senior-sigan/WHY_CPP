#pragma once

#include <whycpp/c_api.h>

typedef void (*Callback)();

typedef struct ApplicationListener_t_ {
  Callback onCreate;
  Callback onDispose;
  Callback onPause;
  Callback onResume;
  Callback onRender;
} ApplicationListener_t;
