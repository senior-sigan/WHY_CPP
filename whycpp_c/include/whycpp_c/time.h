#ifndef WHYCPP_C_TIME_H
#define WHYCPP_C_TIME_H

#include <whycpp/c_api.h>

/**
 * @param context of the application
 * @return time since application was started
 */
WHYCPP_C_API
double GetTime_C();
/**
 * @param context of the application
 * @return time since the last display render event
 */
WHYCPP_C_API
double GetDelta_C();

#endif  // WHYCPP_C_TIME_H
