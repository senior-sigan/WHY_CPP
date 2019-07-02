#pragma once

#include <whycpp/types.h>

class Context;

/**
 * @defgroup Time
 * @ingroup WHYCPP_PublicAPI
 * @brief Functions to get application time
 *
 * @{
 */

/**
 * @param context of the application
 * @return time since application was started
 */
double GetTime(const Context &context);
/**
 * @param context of the application
 * @return time since the last display render event
 */
double GetDelta(const Context &context);

i32 GetFPS(const Context& context);

/** @} */
