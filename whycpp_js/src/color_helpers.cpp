#include "color_helpers.h"
#include <whycpp/log.h>

duk_idx_t PutColor(duk_context *ctx, const RGBA &color) {
  auto colors_idx = duk_push_array(ctx);
  duk_push_number(ctx, color.red);
  duk_put_prop_index(ctx, colors_idx, 0);
  duk_push_number(ctx, color.green);
  duk_put_prop_index(ctx, colors_idx, 1);
  duk_push_number(ctx, color.blue);
  duk_put_prop_index(ctx, colors_idx, 2);
  duk_push_number(ctx, color.alpha);
  duk_put_prop_index(ctx, colors_idx, 3);
  return colors_idx;
}

RGBA GetColor(duk_context *ctx, duk_idx_t idx) {
  RGBA color{};
  auto len = duk_get_length(ctx, idx);
  if (len != 4) {
    LOG_ERROR("Color should be array of 4 ints, but got %d", len);
  } else {
    duk_get_prop_index(ctx, idx, 0);
    color.red = duk_to_uint16(ctx, -1);
    duk_get_prop_index(ctx, idx, 1);
    color.green = duk_to_uint16(ctx, -1);
    duk_get_prop_index(ctx, idx, 2);
    color.blue = duk_to_uint16(ctx, -1);
    duk_get_prop_index(ctx, idx, 3);
    color.alpha = duk_to_uint16(ctx, -1);
  }
  return color;
}