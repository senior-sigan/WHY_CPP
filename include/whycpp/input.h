#ifndef WHYCPP_INPUTS_H
#define WHYCPP_INPUTS_H

enum Button {
  KEY_unknown = 0,
  KEY_SPACE,
  KEY_BACKSPACE,
  KEY_a,
  KEY_b,
  KEY_c,
  KEY_d,
  KEY_e,
  KEY_f,
  KEY_g,
  KEY_h,
  KEY_i,
  KEY_j,
  KEY_k,
  KEY_l,
  KEY_m,
  KEY_n,
  KEY_o,
  KEY_p,
  KEY_q,
  KEY_r,
  KEY_s,
  KEY_t,
  KEY_u,
  KEY_v,
  KEY_w,
  KEY_x,
  KEY_y,
  KEY_z,
  KEY_RIGHT,
  KEY_LEFT,
  KEY_DOWN,
  KEY_UP,
  KEY_LCTRL,
  KEY_LSHIFT,
  KEY_LALT,
  KEY_RCTRL,
  KEY_RSHIFT,
  KEY_RALT,
};

class Context;

bool IsPressed(const Context &ctx, Button btn);
bool IsClicked(const Context &ctx, Button btn);

#endif //WHYCPP_INPUTS_H
