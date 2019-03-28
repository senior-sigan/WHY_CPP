//
// Created by k.leyfer on 27.03.2019.
//

#ifndef WHYCPP_ROOT_WHYCPP_C_H
#define WHYCPP_ROOT_WHYCPP_C_H

#include "application_config.h"
#include "application_listener.h"
#include "c_api.h"

WHYCPP_C_API
void Run(ApplicationListener_t* listener, ApplicationConfig_t* config);

#endif  // WHYCPP_ROOT_WHYCPP_C_H
