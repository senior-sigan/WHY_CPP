#ifndef WHYCPP_CONTEXT_IMPL_H
#define WHYCPP_CONTEXT_IMPL_H

#include <SDL2/SDL_scancode.h>
#include <whycpp/buttons.h>
#include <map>
#include <memory>
#include <string>
#include <vector>
#include "video_memory.h"

struct SDL_Keysym;
class Font;

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
  explicit Context(VideoMemory &vram, Font &font) : vram(vram), font(font) {
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
  bool IsQuit() const;
  void SetQuit(bool quit);
  bool IsPaused() const;
  void SetPaused(bool paused);
  Font &GetFont() const;
  void SetFont(const Font &font);
  int AppendSprite(const VideoMemory &sprite);
  const VideoMemory &GetSprite(int index) const;

  void Tick(double delta);
  void KeyUp(unsigned int code);
  void KeyDown(unsigned int code);
  void ResetKeys();

 private:
  VideoMemory &vram;
  double time = 0.0;
  double current_delta = 0.0;
  std::vector<bool> buttons;
  std::vector<bool> clicked;
  bool quit = false;
  bool paused = false;
  Font &font;
  std::vector<VideoMemory> sprites;

 public:
  int mousePosX = 0;
  int mousePosY = 0;
};

/** @} */

#endif  // WHYCPP_CONTEXT_IMPL_H
