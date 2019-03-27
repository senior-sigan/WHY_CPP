//
// Created by k.leyfer on 27.03.2019.
//

#ifndef WHYCPP_ROOT_APPLICATION_LISTENER_H
#define WHYCPP_ROOT_APPLICATION_LISTENER_H

#include "c_api.h"
#include "context.h"

typedef void (*Callback)(struct Context_t_* context);

typedef struct ApplicationListener_t_ {
  Callback onCreate;
  Callback onDispose;
  Callback onPause;
  Callback onResume;
  Callback onRender;
} ApplicationListener_t;

#endif  // WHYCPP_ROOT_APPLICATION_LISTENER_H
