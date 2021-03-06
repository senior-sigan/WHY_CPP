#pragma once

#include <duktape.h>

int GetDukInt(duk_context *ctx, int idx, int null_case);
const char *GetDukStr(duk_context *ctx, int idx, const char *null_case);
bool GetDukBool(duk_context *ctx, int idx, bool null_case);

void PushFileAsString(duk_context *ctx, const char *filename);

void RunScript(duk_context *ctx, const char* filename);

void RegisterConstant(duk_context *ctx, const char *name, duk_double_t value);
