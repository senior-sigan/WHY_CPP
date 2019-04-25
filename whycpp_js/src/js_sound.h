#ifndef WHYCPP_ROOT_WHYCPP_JS_SRC_JS_SOUND_H_
#define WHYCPP_ROOT_WHYCPP_JS_SRC_JS_SOUND_H_

#include <duktape.h>

duk_ret_t js_ImportMusic(duk_context *ctx);
duk_ret_t js_ImportSFX(duk_context *ctx);
duk_ret_t js_PlayMusic(duk_context *ctx);
duk_ret_t js_PlaySFX(duk_context *ctx);

#endif  // WHYCPP_ROOT_WHYCPP_JS_SRC_JS_SOUND_H_
