#pragma once

#include <whycpp/c_api.h>
#include <whycpp_c/application_config.h>
#include <whycpp_c/application_listener.h>

WHYCPP_C_API
void Run(ApplicationListener_t* listener, ApplicationConfig_t* config);
