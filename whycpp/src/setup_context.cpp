#include "setup_context.h"
#include <whycpp/application_config.h>
#include "context.h"
#include "holders/audio_holder.h"
#include "holders/fonts_holder.h"
#include "holders/fps_holder.h"
#include "holders/keyboard_holder.h"
#include "holders/lifecycle_holder.h"
#include "holders/mouse_holder.h"
#include "holders/sprites_holder.h"
#include "holders/time_holder.h"
#include "holders/video_memory_holder.h"

void SetupContext(Context* ctx, const ApplicationConfig& config) {
  ctx->Put<AudioHolder>();
  ctx->Put<FpsHolder>(config);
  ctx->Put<TimeHolder>();
  ctx->Put<SpritesHolder>();
  ctx->Put<FontsHolder>();
  ctx->Put<KeyboardHolder>();
  ctx->Put<MouseHolder>();
  ctx->Put<LifecycleHolder>();
  ctx->Put<VideoMemoryHolder>(config.width, config.height);
}
