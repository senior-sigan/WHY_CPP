#ifndef WHYCPP_ROOT_WHYCPP_JS_SRC_JS_CONFIG_READER_H_
#define WHYCPP_ROOT_WHYCPP_JS_SRC_JS_CONFIG_READER_H_

#include <duk_config.h>
#include <whycpp/application_config.h>

ApplicationConfig GetConfig(duk_context *ctx);

#endif  // WHYCPP_ROOT_WHYCPP_JS_SRC_JS_CONFIG_READER_H_
