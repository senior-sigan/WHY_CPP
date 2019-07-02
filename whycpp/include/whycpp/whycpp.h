#pragma once

#include <whycpp/application_config.h>
#include <memory>

class ApplicationListener;

/**
 * @defgroup WHYCPP_PublicAPI WHYCPP Public API
 * @brief API for game developers.
 */

/**
 * @defgroup Application
 * @ingroup WHYCPP_PublicAPI
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
void RunApp(const ApplicationConfig &config = ApplicationConfig(256, 144, "Application", false, 3, 16)) {
  Run(new Listener(), config);
}

/**
 * Run the application and lock the main thread.
 * To unlock the thread the application should be stopped somehow.
 *
 * @param listener is an ApplicationListener implementation
 * @param config is the configuration of the application
 */
void Run(ApplicationListener *listener,
         const ApplicationConfig &config = ApplicationConfig(256, 144, "Application", false, 3, 16));

/** @} */
