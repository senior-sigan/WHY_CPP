#pragma once

#include <whycpp/c_api.h>

/**
 * Pause the application rendering.
 */
WHYCPP_C_API
void PauseApp_C();

/**
 * Resume the application rendering.
 */
WHYCPP_C_API
void ResumeApp_C();

/**
 * Completely stop the application.
 * After this the OnDispose of the ApplicationListener will be called.
 */
WHYCPP_C_API
void ExitApp_C();
