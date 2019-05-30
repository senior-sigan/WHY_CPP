#include <memory>

#include <whycpp/application_config.h>
#include <whycpp/application_listener.h>
#include <functional>
#include "application.h"
#include "context.h"
#include "default_font.h"
#include "global_app_context.h"
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
  SetContext(context.get());  // TODO: it's ugly, more elegnt way should be found!

  Loop::Callback update = [=](double delta_time) {
    if (!GetContext().IsPaused()) {
      GetContext().Tick(delta_time);
      listener->OnRender();
    }
  };
  Loop::Callback render = [=](double) { GetContext().GetSDLContext()->GetRenderer()->Render(); };
  Loop::Callback inputs = [=](double) { GetContext().GetInputsHandler()->HandleEvents(); };
  loop = std::make_unique<Loop>(update, render, inputs, this->listener.get(), config.ms_per_frame);
}
void Application::Run() {
  context->InitSDL();
  loop->Run();  // this call is async in case of emscripten
}
Application::~Application() {
  LOG_DEBUG("Application destroyed");
}
