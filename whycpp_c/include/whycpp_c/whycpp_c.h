#ifndef WHYCPP_C_WHYCPP_C_H
#define WHYCPP_C_WHYCPP_C_H

#include <whycpp/c_api.h>
#include "application_config.h"
#include "application_listener.h"

WHYCPP_C_API
void Run(ApplicationListener_t* listener, ApplicationConfig_t* config);

#endif  // WHYCPP_C_WHYCPP_C_H
