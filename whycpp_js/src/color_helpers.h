#ifndef WHYCPP_ROOT_WHYCPP_JS_SRC_COLOR_HELPERS_H_
#define WHYCPP_ROOT_WHYCPP_JS_SRC_COLOR_HELPERS_H_

#include <duktape.h>
#include <whycpp/color.h>

duk_idx_t PutColor(duk_context *ctx, const RGBA &color);
RGBA GetColor(duk_context *ctx, duk_idx_t idx);

#endif //WHYCPP_ROOT_WHYCPP_JS_SRC_COLOR_HELPERS_H_
