#pragma once

#include <duktape.h>
#include <whycpp/color.h>

duk_idx_t PutColor(duk_context *ctx, const RGBA &color);
RGBA GetColor(duk_context *ctx, duk_idx_t idx);
