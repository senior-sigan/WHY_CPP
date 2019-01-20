#ifndef WHYCPP_CONTEXT_IMPL_H
#define WHYCPP_CONTEXT_IMPL_H

#include <vector>
#include <whycpp/buttons.h>

class VideoMemory;
struct SDL_Keysym;

/**
 * @addtogroup ApplicationInternals
 * @ingroup Internals
 *
 * @{
 */

/**
 * @class Context
 *
 * Context implementation is hidden from the users, because it contains some low-level logic.
 * Users are supposed to use a forward declaration of the context and functions
 * which receives Context as a parameter.
 *
 * @see WHYCPP_PublicAPI
 */
class Context {
 public:
  explicit Context(VideoMemory &vram) : vram(vram) {
    buttons.resize(Button::KEY_NUM_KEYS);
    clicked.resize(Button::KEY_NUM_KEYS);
  }
  virtual ~Context() = default;

  VideoMemory &GetVRAM() const {
    return vram;
  }
  double GetTime() const {
    return time;
  }
  double GetDelta() const {
    return current_delta;
  }
  bool IsButtonPressed(const Button &btn) const {
    if (btn >= buttons.size()) return false;
    return buttons.at(btn);
  }
  bool IsButtonReleased(const Button &btn) const {
    if (btn >= buttons.size()) return false;
    return clicked.at(btn);
  }

  void Tick(double delta);
  void KeyUp(const SDL_Keysym &keysym);
  void KeyDown(const SDL_Keysym &keysym);
  void ResetKeys();
 private:
  VideoMemory &vram;
  double time = 0.0;
  double current_delta = 0.0;
  std::vector<bool> buttons;
  std::vector<bool> clicked;
};

/** @} */

#endif //WHYCPP_CONTEXT_IMPL_H
