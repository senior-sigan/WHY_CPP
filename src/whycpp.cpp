#include <whycpp/application_listener.h>
#include "application.h"

void Run(std::shared_ptr<ApplicationListener> listener, const ApplicationConfig &config) {
  Application app(listener, config);
  app.Run();
}