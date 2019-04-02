#ifndef WHYCPP_LOG_H
#define WHYCPP_LOG_H

enum LogLevel {
  VERBOSE = 1,
  DEBUG,
  INFO,
  WARN,
  ERROR,
  CRITICAL
};

void LogMessage(LogLevel level, const char* fmt, ...);

#define LOG_VERBOSE(FMT, ...) LogMessage(VERBOSE, FMT, ## __VA_ARGS__)
#define LOG_DEBUG(FMT, ...) LogMessage(DEBUG, FMT, ## __VA_ARGS__)
#define LOG_INFO(FMT, ...) LogMessage(INFO, FMT, ## __VA_ARGS__)
#define LOG_WARN(FMT, ...) LogMessage(WARN, FMT, ## __VA_ARGS__)
#define LOG_ERROR(FMT, ...) LogMessage(ERROR, FMT, ## __VA_ARGS__)
#define LOG_CRITICAL(FMT, ...) LogMessage(CRITICAL, FMT, ## __VA_ARGS__)

void SetLogLevel(LogLevel priority);

#endif  // WHYCPP_LOG_H
