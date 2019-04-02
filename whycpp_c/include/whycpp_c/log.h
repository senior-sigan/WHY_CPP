#ifndef WHYCPP_C_LOG_H
#define WHYCPP_C_LOG_H

#include "c_api.h"

typedef enum {
    VERBOSE = 1,
    DEBUG,
    INFO,
    WARN,
    ERROR,
    CRITICAL
} LogLevel_t;

WHYCPP_C_API
void LogMessage_C(LogLevel_t level, const char* fmt, ...);

#define LOG_VERBOSE(FMT, ...) LogMessage_C(VERBOSE, FMT, ## __VA_ARGS__)
#define LOG_DEBUG(FMT, ...) LogMessage_C(DEBUG, FMT, ## __VA_ARGS__)
#define LOG_INFO(FMT, ...) LogMessage_C(INFO, FMT, ## __VA_ARGS__)
#define LOG_WARN(FMT, ...) LogMessage_C(WARN, FMT, ## __VA_ARGS__)
#define LOG_ERROR(FMT, ...) LogMessage_C(ERROR, FMT, ## __VA_ARGS__)
#define LOG_CRITICAL(FMT, ...) LogMessage_C(CRITICAL, FMT, ## __VA_ARGS__)

WHYCPP_C_API
void SetLogLevel_C(LogLevel_t priority);

#endif  // WHYCPP_C_LOG_H
