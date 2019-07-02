#pragma once

class Context;

/**
 * @addtogroup Application
 * @{
 */

/**
 * @class ApplicationListener
 *
 * ApplicationListener is the entry poi32 into the WHYCPP application.
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
  virtual void OnCreate(Context &) {}
  virtual void OnDispose(Context &) {}
  virtual void OnPause(Context &) {}
  virtual void OnResume(Context &) {}
  virtual void OnRender(Context &) {}
  virtual ~ApplicationListener() = default;
};

/** @} */
