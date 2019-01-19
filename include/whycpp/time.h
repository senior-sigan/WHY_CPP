#ifndef WHYCPP_TIME_H
#define WHYCPP_TIME_H

class Context;

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

#endif //WHYCPP_TIME_H
