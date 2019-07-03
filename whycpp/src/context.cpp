#include "context.h"
#include "holders/audio_holder.h"
#include "holders/fonts_holder.h"
#include "holders/fps_holder.h"
#include "holders/keyboard_holder.h"
#include "holders/lifecycle_holder.h"
#include "holders/mouse_holder.h"
#include "holders/sprites_holder.h"
#include "holders/time_holder.h"
#include "logger.h"
#include "video_memory.h"

Context::~Context() {
  LOG_DEBUG("Context destroyed");
}
Context::Context(const ApplicationConfig& config) : config_(config) {
  container = std::make_unique<Container>();
  container->Put<AudioHolder>();
  container->Put<FpsHolder>(config);
  container->Put<TimeHolder>();
  container->Put<SpritesHolder>();
  container->Put<FontsHolder>();
  container->Put<KeyboardHolder>();
  container->Put<MouseHolder>();
  container->Put<LifecycleHolder>();
  container->Put<VideoMemory>(config.width, config.height);

  LOG_DEBUG("Context created");
}
