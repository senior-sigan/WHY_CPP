#pragma once

#include <duktape.h>

duk_ret_t js_ImportMusic(duk_context *ctx);
duk_ret_t js_ImportSFX(duk_context *ctx);
duk_ret_t js_PlayMusic(duk_context *ctx);
duk_ret_t js_PlaySFX(duk_context *ctx);
