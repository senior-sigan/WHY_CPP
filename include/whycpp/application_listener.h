#ifndef WHYCPP_APPLICATION_LISTENER_H
#define WHYCPP_APPLICATION_LISTENER_H

class Context;

class ApplicationListener {
 public:
  virtual void OnCreate(Context&) {};
  virtual void OnDispose(Context&) {};
  virtual void OnPause(Context&) {};
  virtual void OnResume(Context&) {};
  virtual void OnRender(Context&) {};
  virtual ~ApplicationListener() = default;
};

#endif //WHYCPP_APPLICATION_LISTENER_H
