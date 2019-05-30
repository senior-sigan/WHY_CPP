#ifndef WHYCPP_LIFECYCLE_H
#define WHYCPP_LIFECYCLE_H

/**
 * @defgroup LifeCycle
 * @ingroup WHYCPP_PublicAPI
 * @brief Functions to control application life cycle.
 *
 * @{
 */

/**
 * Pause the application rendering.
 */
void PauseApp();

/**
 * Resume the application rendering.
 */
void ResumeApp();

/**
 * Completely stop the application.
 * After this the OnDispose of the ApplicationListener will be called.
 */
void ExitApp();

/**
 * @}
 */

#endif  // WHYCPP_LIFECYCLE_H
