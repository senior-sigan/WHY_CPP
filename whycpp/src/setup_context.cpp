#include "setup_context.h"
#include <whycpp/application_config.h>
#include <whycpp/application_listener.h>
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
#include "loop/i_render_handler.h"
#include "loop/loop_impl.h"
#include "sdl_specific/sdl_audio_context.h"
#include "sdl_specific/sdl_inputs_handler.h"
#include "sdl_specific/sdl_render_context.h"

void SetupContext(Context& ctx, const ApplicationConfig& config, ApplicationListener* listener) {
  ctx.Put<AudioHolder>();
  ctx.Put<FpsHolder>(config);
  ctx.Put<TimeHolder>();
  ctx.Put<SpritesHolder>();
  ctx.Put<FontsHolder>();
  ctx.Put<KeyboardHolder>();
  ctx.Put<MouseHolder>();
  ctx.Put<LifecycleHolder>();
  auto vram = ctx.Put<VideoMemoryHolder>(config.width, config.height);

  ctx.PutAs<SDLInputsHandler, IInputsHandler>(ctx, listener);
  ctx.PutAs<SDLRenderContext, IRenderHandler>(config, vram);
  ctx.Put<SDLAudioContext>();
  ctx.PutAs<LoopImpl, ILoop>(ctx, listener, config.ms_per_frame);
}
