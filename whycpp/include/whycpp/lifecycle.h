#pragma once

class Context;

/**
 * @defgroup LifeCycle
 * @ingroup WHYCPP_PublicAPI
 * @brief Functions to control application life cycle.
 *
 * @{
 */

/**
 * Pause the application rendering.
 * @param context of the application
 */
void PauseApp(Context &context);

/**
 * Resume the application rendering.
 * @param context of the application
 */
void ResumeApp(Context &context);

/**
 * Completely stop the application.
 * After this the OnDispose of the ApplicationListener will be called.
 * @param context of the application
 */
void ExitApp(Context &context);

/**
 * @}
 */
