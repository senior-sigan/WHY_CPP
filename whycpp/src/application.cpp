#include <memory>

#include "application.h"
#include <whycpp/application_config.h>
#include <whycpp/application_listener.h>
#include <functional>
#include "context.h"
#include "default_font.h"
#include "logger.h"
#include "loop.h"
#include "sdl_specific/sdl_context.h"
#include "sdl_specific/sdl_texture.h"
#include "video_memory.h"
#include "inputs_handler.h"

Application::Application(ApplicationListener* listener, const ApplicationConfig& config)
    : listener(std::unique_ptr<ApplicationListener>(listener)), config(config) {
  LOG_DEBUG("Application Created");

  auto vram = new VideoMemory(config.width, config.height);
  auto font = BuildDefaultFont();
  context = std::make_unique<Context>(vram, font);

  Loop::Callback lambda = [=](Context& ctx, double delta_time) { Update(ctx, delta_time); };
  loop = std::make_unique<Loop>(lambda, *context, this->listener.get(), config.ms_per_frame);

  input_handler_ = std::make_unique<InputsHandler>(this->listener.get());
}
void Application::Run() {
  loop->Run();  // this call is async in case of emscripten
}
void Application::Update(Context& ctx, double delta_time) {
  input_handler_->HandleEvents(ctx);
  if (!ctx.IsPaused()) {
    ctx.Tick(delta_time);
    listener->OnRender(ctx);
    RenderOrInit();
  }
}
void Application::RenderOrInit() {
  if (!sdl_context) {
    // YES. I know about class invariant, but we need this becasue of emscripten + sdl2 lifecycle problems.
    // Also, this is pattern "lazy".
    sdl_context = std::make_unique<SDLContext>(config, context->GetVRAM());
  }
  sdl_context->Render();
}
Application::~Application() {
  LOG_DEBUG("Application destroyed");
}
