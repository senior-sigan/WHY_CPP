#include <SDL_error.h>
#include <SDL_log.h>
#include <cstdio>
#include "../logger.h"

void LogSDLError(const std::string& msg) {
  LOG_ERROR("%s error: %s", msg.c_str(), SDL_GetError());
}

void LogMessageV(SDL_LogPriority priority, const char* fmt, va_list args) {
  SDL_LogMessageV(SDL_LOG_CATEGORY_CUSTOM, priority, fmt, args);
}

void LogMessage(LogLevel priority, const char* fmt, ...) {
  auto sdl_priority = static_cast<SDL_LogPriority>(static_cast<int>(priority));
  va_list args;
  va_start(args, fmt);
  LogMessageV(sdl_priority, fmt, args);
  va_end(args);
}

void SetLogLevel(LogLevel log_level) {
  // We hope it works and nobody changes SDL priorities order
  auto sdl_priority = static_cast<SDL_LogPriority>(static_cast<int>(log_level));
  SDL_LogSetAllPriority(sdl_priority);
}
