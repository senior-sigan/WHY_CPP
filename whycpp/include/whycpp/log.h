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

void LogVerbose(const char *fmt, ...);
void LogDebug(const char *fmt, ...);
void LogInfo(const char *fmt, ...);
void LogWarn(const char *fmt, ...);
void LogError(const char *fmt, ...);
void LogCritical(const char *fmt, ...);

void SetLogLevel(LogLevel priority);

#endif  // WHYCPP_LOG_H