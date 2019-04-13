#ifndef WHYCPP_CONTEXT_IMPL_H
#define WHYCPP_CONTEXT_IMPL_H

#include <map>
#include <memory>
#include <string>
#include <vector>

#include <whycpp/buttons.h>
#include "../../whycpp_js/src/global_app_context.h"


class Font;
class VideoMemory;

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
  explicit Context(VideoMemory *vram, Font *font);
  virtual ~Context();

  VideoMemory *GetVRAM() const;
  double GetTime() const {
    return time;
  }
  double GetDelta() const {
    return current_delta;
  }
  bool IsButtonPressed(const Button &btn) const;
  bool IsButtonReleased(const Button &btn) const;
  bool IsQuit() const;
  void SetQuit(bool quit);
  bool IsPaused() const;
  void SetPaused(bool paused);
  Font *GetFont() const;
  void SetFont(Font *font);
  int AppendSprite(VideoMemory *sprite);
  VideoMemory *GetSprite(int index) const;

  void Tick(double delta);
  void KeyUp(unsigned int code);
  void KeyDown(unsigned int code);
  void ResetKeys();

 private:
  std::unique_ptr<VideoMemory> vram;
  double time = 0.0;
  double current_delta = 0.0;
  std::vector<bool> buttons;
  std::vector<bool> clicked;
  bool quit = false;
  bool paused = false;
  std::unique_ptr<Font> font;
  std::vector<std::unique_ptr<VideoMemory>> sprites;

 public:
  int mousePosX = 0;
  int mousePosY = 0;
};

/** @} */

#endif  // WHYCPP_CONTEXT_IMPL_H
