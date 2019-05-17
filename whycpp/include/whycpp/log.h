#ifndef WHYCPP_LOG_H
#define WHYCPP_LOG_H

#include <whycpp/c_api.h>

/**
 * @defgroup Logging
 * @ingroup WHYCPP_PublicAPI
 * @brief Functions to write logs into console.
 *
 * @{
 */

typedef enum LogLevel {
  VERBOSE = 1,
  DEBUG,
  INFO,
  WARN,
  ERROR,
  CRITICAL
} LogLevel_t;

/**
 * Print a message to the console.
 * It works like printf.
 * @param level
 * @param fmt printf-style format string
 * @param ...
 */
WHYCPP_C_API
void LogMessage(LogLevel_t level, const char* fmt, ...);

#define LOG_VERBOSE(FMT, ...) LogMessage(VERBOSE, FMT, ## __VA_ARGS__)
#define LOG_DEBUG(FMT, ...) LogMessage(DEBUG, FMT, ## __VA_ARGS__)
#define LOG_INFO(FMT, ...) LogMessage(INFO, FMT, ## __VA_ARGS__)
#define LOG_WARN(FMT, ...) LogMessage(WARN, FMT, ## __VA_ARGS__)
#define LOG_ERROR(FMT, ...) LogMessage(ERROR, FMT, ## __VA_ARGS__)
#define LOG_CRITICAL(FMT, ...) LogMessage(CRITICAL, FMT, ## __VA_ARGS__)

/**
 * Set global application log level.
 * To see library messages you need to set DEBUG level.
 * @param priority
 */
WHYCPP_C_API
void SetLogLevel(LogLevel_t priority);

/** @} */

#endif  // WHYCPP_LOG_H
