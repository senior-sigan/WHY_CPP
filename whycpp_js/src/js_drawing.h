#ifndef WHYCPP_ROOT_WHYCPP_JS_SRC_JS_DRAWING_H_
#define WHYCPP_ROOT_WHYCPP_JS_SRC_JS_DRAWING_H_

#include <duktape.h>

duk_ret_t js_GetDisplayWidth(duk_context *ctx);
duk_ret_t js_GetDisplayHeight(duk_context *ctx);
duk_ret_t js_SetPixel(duk_context *ctx);
duk_ret_t js_GetPixel(duk_context *ctx);
duk_ret_t js_DrawClearScreen(duk_context *ctx);
duk_ret_t js_DrawLine(duk_context *ctx);
duk_ret_t js_DrawRectFill(duk_context *ctx);
duk_ret_t js_DrawRect(duk_context *ctx);
duk_ret_t js_DrawCircle(duk_context *ctx);
duk_ret_t js_DrawCircleFill(duk_context *ctx);
duk_ret_t js_DrawSprite(duk_context *ctx);

#endif //WHYCPP_ROOT_WHYCPP_JS_SRC_JS_DRAWING_H_
