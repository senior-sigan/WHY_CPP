//
// Created by k.leyfer on 28.03.2019.
//

#ifndef WHYCPP_ROOT_TIME_H
#define WHYCPP_ROOT_TIME_H

#include "c_api.h"

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

#endif  // WHYCPP_ROOT_TIME_H
