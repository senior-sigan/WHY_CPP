#ifndef WHYCPP_APPLICATION_LISTENER_H
#define WHYCPP_APPLICATION_LISTENER_H

/**
 * @addtogroup Application
 * @{
 */

/**
 * @class ApplicationListener
 *
 * ApplicationListener is the entry point into the WHYCPP application.
 * Usually you need only one implementation of this interface,
 * but in case you would like to have many different applications in a single binary file,
 * you could create more implementations.
 *
 * To run the application you should use Run() or RunApp() function with your implementation:
 * @code RunApp(new YourImplementation(), config) @endcode
 * @code Run<YourImplementation>(config) @endcode
 *
 * @sa RunApp()
 * @sa Run()
 *
 */
class ApplicationListener {
 public:
  virtual void OnCreate() {}
  virtual void OnDispose() {}
  virtual void OnPause() {}
  virtual void OnResume() {}
  virtual void OnRender() {}
  virtual ~ApplicationListener() = default;
};

/** @} */

#endif  // WHYCPP_APPLICATION_LISTENER_H
