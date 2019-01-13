#include <whycpp/application_listener.h>
#include "application.h"

void Run(ApplicationListener *listener) {
  Application app(listener);
  app.Run();
}