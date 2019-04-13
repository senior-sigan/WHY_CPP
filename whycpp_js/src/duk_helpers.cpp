#include "duk_helpers.h"
#include <string>

int GetDukInt(duk_context* ctx, int idx, int null_case) {
  return duk_is_null_or_undefined(ctx, idx) ? null_case : duk_to_int(ctx, idx);
}
const char* GetDukStr(duk_context* ctx, int idx, const char* null_case) {
  return duk_is_null_or_undefined(ctx, idx) ? null_case : duk_to_string(ctx, idx);
}
bool GetDukBool(duk_context* ctx, int idx, bool null_case) {
  return duk_is_null_or_undefined(ctx, idx) ? null_case : duk_to_boolean(ctx, idx);
}
void PushFileAsString(duk_context* ctx, const char* filename) {
  FILE *f;
  size_t len;
  char buf[16384];

  f = fopen(filename, "rb");
  if (f) {
    len = fread((void *) buf, 1, sizeof(buf), f);
    fclose(f);
    duk_push_lstring(ctx, (const char *) buf, (duk_size_t) len);
  } else {
    duk_push_undefined(ctx);
  }
}
void RunScript(duk_context* ctx, const char* filename) {
  PushFileAsString(ctx, filename);
  if (duk_peval(ctx) != 0) {
    printf("Error: %s\n", duk_safe_to_string(ctx, -1));
    return;
  }
  duk_pop(ctx);
}
