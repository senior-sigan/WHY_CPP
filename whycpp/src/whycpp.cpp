#include <whycpp/application_listener.h>
#include "application.h"
#include "logger.h"

void Run(ApplicationListener* listener, const ApplicationConfig& config) {
#if __EMSCRIPTEN__
  auto app = new Application(listener, config);
  app->Run();
  // do not destroy this object
#else
  Application app(listener, config);
  app.Run();
#endif
}