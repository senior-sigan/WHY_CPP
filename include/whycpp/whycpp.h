#ifndef WHYCPP_WHYCPP_H
#define WHYCPP_WHYCPP_H

#include "application_config.h"

class ApplicationListener;

/**
 * @defgroup Application
 * @brief Functions to configure application start-up
 *
 * @{
 */

/**
 * It's a wrapper for the `Run` function to hide the process of allocating memory for the ApplicationListener object.
 * @tparam Listener is an ApplicationListener implementation
 * @param config is the configuration of the application
 */
template<typename Listener>
void RunApp(const ApplicationConfig &config = {256, 144, "Application"}) {
  Listener l;
  Run(&l, config);
}

/**
 * Run the application and lock the main thread.
 * To unlock the thread the application should be stopped somehow.
 *
 * @param listener is an ApplicationListener implementation
 * @param config is the configuration of the application
 */
void Run(ApplicationListener *listener, const ApplicationConfig &config = {256, 144, "Application"});

/** @} */

#endif //WHYCPP_WHYCPP_H
