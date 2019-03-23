#include "logger.h"
#include <SDL2/SDL_error.h>
#include <SDL2/SDL_log.h>
#include <cstdio>

void LogSDLError(const std::string& msg) {
  LogError("%s error: %s", msg.c_str(), SDL_GetError());
}

void LogMessageV(SDL_LogPriority priority, const char* fmt, va_list args) {
  SDL_LogMessageV(SDL_LOG_CATEGORY_CUSTOM, priority, fmt, args);
}

void LogDebug(const char* fmt, ...) {
  va_list args;
  va_start(args, fmt);
  LogMessageV(SDL_LOG_PRIORITY_DEBUG, fmt, args);
  va_end(args);
}

void LogError(const char* fmt, ...) {
  va_list args;
  va_start(args, fmt);
  LogMessageV(SDL_LOG_PRIORITY_ERROR, fmt, args);
  va_end(args);
}

void LogInfo(const char* fmt, ...) {
  va_list args;
  va_start(args, fmt);
  LogMessageV(SDL_LOG_PRIORITY_INFO, fmt, args);
  va_end(args);
}

void LogVerbose(const char* fmt, ...) {
  va_list args;
  va_start(args, fmt);
  LogMessageV(SDL_LOG_PRIORITY_VERBOSE, fmt, args);
  va_end(args);
}
void LogWarn(const char* fmt, ...) {
  va_list args;
  va_start(args, fmt);
  LogMessageV(SDL_LOG_PRIORITY_WARN, fmt, args);
  va_end(args);
}
void LogCritical(const char* fmt, ...) {
  va_list args;
  va_start(args, fmt);
  LogMessageV(SDL_LOG_PRIORITY_CRITICAL, fmt, args);
  va_end(args);
}

void SetLogLevel(LogLevel log_level) {
  // We hope it works and nobody changes SDL priorities order
  auto sdl_priority = static_cast<SDL_LogPriority>(static_cast<int>(log_level));
  SDL_LogSetAllPriority(sdl_priority);
}