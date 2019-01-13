#ifndef WHYCPP_APPLICATION_LISTENER_H
#define WHYCPP_APPLICATION_LISTENER_H

#include <whycpp/context.h>

class ApplicationListener {
 public:
  virtual void OnCreate() {};
  virtual void OnDispose() {};
  virtual void OnPause() {};
  virtual void OnRender(Context&) {};
  virtual ~ApplicationListener() = default;
};

#endif //WHYCPP_APPLICATION_LISTENER_H
