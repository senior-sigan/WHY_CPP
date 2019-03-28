//
// Created by kirill on 27.03.19.
//

#ifndef WHYCPP_ROOT_APPLICATION_LISTENER_INT_H
#define WHYCPP_ROOT_APPLICATION_LISTENER_INT_H

#include <whycpp/application_listener.h>
#include <whycpp_c/application_listener.h>
#include "global_context_int.h"

class CallbackApplicationListener : public ApplicationListener {
 public:
  CallbackApplicationListener(ApplicationListener_t *applicationListener) : listener(applicationListener) {}

  void OnCreate(Context &context) override {
    SetContext_C(&context);
    if (listener->onCreate != nullptr) {
      listener->onCreate();
    }
  }

  void OnDispose(Context &context) override {
    if (listener->onDispose != nullptr) {
      listener->onDispose();
    }
  }

  void OnPause(Context &context) override {
    if (listener->onPause != nullptr) {
      listener->onPause();
    }
  }

  void OnResume(Context &context) override {
    if (listener->onResume != nullptr) {
      listener->onResume();
    }
  }

  void OnRender(Context &context) override {
    if (listener->onRender != nullptr) {
      listener->onRender();
    }
  }

 private:
  ApplicationListener_t *listener;
};

#endif  // WHYCPP_ROOT_APPLICATION_LISTENER_INT_H
