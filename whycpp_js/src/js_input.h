#ifndef WHYCPP_ROOT_WHYCPP_JS_SRC_JS_INPUT_H_
#define WHYCPP_ROOT_WHYCPP_JS_SRC_JS_INPUT_H_

#include <duktape.h>

void RegisterButtons(duk_context *ctx);

duk_ret_t js_IsClicked(duk_context *ctx);
duk_ret_t js_IsPressed(duk_context *ctx);
duk_ret_t js_GetMouse(duk_context *ctx);

#endif //WHYCPP_ROOT_WHYCPP_JS_SRC_JS_INPUT_H_
