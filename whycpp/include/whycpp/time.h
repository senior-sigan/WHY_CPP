#ifndef WHYCPP_TIME_H
#define WHYCPP_TIME_H

/**
 * @defgroup Time
 * @ingroup WHYCPP_PublicAPI
 * @brief Functions to get application time
 *
 * @{
 */

/**
 * @return time since application was started
 */
double GetTime();
/**
 * @return time since the last display render event
 */
double GetDelta();

int GetFPS();

/** @} */

#endif  // WHYCPP_TIME_H
