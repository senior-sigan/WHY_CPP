#include <whycpp_c/log.h>
#include <SDL2/SDL_error.h>
#include <SDL2/SDL_log.h>
#include <cstdio>

void LogMessageV_C(SDL_LogPriority priority, const char* fmt, va_list args) {
  SDL_LogMessageV(SDL_LOG_CATEGORY_CUSTOM, priority, fmt, args);
}

void LogMessage_C(LogLevel_t priority, const char* fmt, ...) {
  auto sdl_priority = static_cast<SDL_LogPriority>(static_cast<int>(priority));
  va_list args;
  va_start(args, fmt);
  LogMessageV_C(sdl_priority, fmt, args);
  va_end(args);
}

void SetLogLevel_C(LogLevel_t log_level) {
  // We hope it works and nobody changes SDL priorities order
  auto sdl_priority = static_cast<SDL_LogPriority>(static_cast<int>(log_level));
  SDL_LogSetAllPriority(sdl_priority);
}
