#ifndef WHYCPP_APPLICATION_LISTENER_H
#define WHYCPP_APPLICATION_LISTENER_H

#include <whycpp/context.h>

class ApplicationListener {
 public:
  virtual void OnCreate() = 0;
  virtual void OnDispose() = 0;
  virtual void OnPause() = 0;
  virtual void OnRender(Context&) = 0;
  virtual ~ApplicationListener() = default;
};

#endif //WHYCPP_APPLICATION_LISTENER_H
