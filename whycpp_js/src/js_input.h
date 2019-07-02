#pragma once

#include <duktape.h>

void RegisterButtons(duk_context *ctx);

duk_ret_t js_IsClicked(duk_context *ctx);
duk_ret_t js_IsPressed(duk_context *ctx);
duk_ret_t js_GetMouse(duk_context *ctx);
