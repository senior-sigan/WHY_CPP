#include "application.h"
#include <whycpp/application_config.h>
#include <whycpp/application_listener.h>
#include <functional>
#include <memory>
#include "context.h"
#include "default_font.h"
#include "holders/lifecycle_holder.h"
#include "holders/time_holder.h"
#include "inputs_handler.h"
#include "logger.h"
#include "loop.h"
#include "sdl_specific/sdl_context.h"
#include "sdl_specific/sdl_render_context.h"
#include "sdl_specific/sdl_texture.h"
#include "video_memory.h"

Application::Application(ApplicationListener* listener, const ApplicationConfig& config)
    : listener(std::unique_ptr<ApplicationListener>(listener)), config(config) {
  LOG_DEBUG("Application Created");

  context = std::make_unique<Context>(config);

  Loop::Callback update = [=](Context& ctx, double delta_time) {
    if (!ctx.container->Get<LifecycleHolder>()->IsPaused()) {
      ctx.container->Get<TimeHolder>()->Tick(delta_time);
      listener->OnRender(ctx);
    }
  };
  Loop::Callback render = [=](Context&, double) { sdl_context->GetRenderer()->Render(); };
  Loop::Callback inputs = [=](Context& ctx, double) { input_handler_->HandleEvents(ctx); };
  loop = std::make_unique<Loop>(update, render, inputs, *context, this->listener.get(), config.ms_per_frame);

  input_handler_ = std::make_unique<InputsHandler>(this->listener.get());
}
void Application::Run() {
  sdl_context = std::make_unique<SDLContext>(config, context->container->Get<VideoMemory>());
  loop->Run();  // this call is async in case of emscripten
}
Application::~Application() {
  LOG_DEBUG("Application destroyed");
}
