#ifndef WHYCPP_CONTEXT_IMPL_H
#define WHYCPP_CONTEXT_IMPL_H

#include <map>
#include <memory>
#include <string>
#include <vector>
#include "average_window.h"
#include "inputs_handler.h"
#include "sdl_specific/sdl_context.h"

#include <whycpp/application_config.h>
#include <whycpp/buttons.h>
#include <whycpp/font.h>

class VideoMemory;
class Sprite;
class SFX;
class Music;

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
  explicit Context(const ApplicationConfig &config);
  virtual ~Context();

  void InitSDL() {
    sdl_context = std::make_unique<SDLContext>(config_, vram_.get());
  }
  SDLContext *GetSDLContext() const {
    return sdl_context.get();
  }
  InputsHandler *GetInputsHandler() const {
    return input_handler_.get();
  }

  VideoMemory *GetVRAM() const;
  double GetTime() const {
    return time_;
  }
  double GetDelta() const {
    return current_delta_;
  }
  bool IsButtonPressed(const Button &btn) const;
  bool IsButtonReleased(const Button &btn) const;
  bool IsQuit() const;
  void SetQuit(bool quit);
  bool IsPaused() const;
  void SetPaused(bool paused);
  Font GetFont() const;
  void SetFont(const Font &font);
  int AppendSprite(Sprite *sprite);
  Sprite *GetSprite(int index) const;

  void RegisterMusic(const std::string &path, const std::string &name);
  Music *GetMusic(const std::string &name) const;
  void RegisterSFX(const std::string &path, const std::string &name);
  SFX *GetSFX(const std::string &name) const;

  void Tick(double delta);
  void SetRealDeltaTime(double delta);
  void KeyUp(unsigned int code);
  void KeyDown(unsigned int code);
  void ResetKeys();
  int GetFPS() const;

 private:
  std::unique_ptr<VideoMemory> vram_;
  const ApplicationConfig config_;
  double time_ = 0.0;
  double current_delta_ = 0.0;
  std::vector<bool> buttons_;
  std::vector<bool> clicked_;
  bool quit_ = false;
  bool paused_ = false;
  Font font_;
  std::vector<std::unique_ptr<Sprite>> sprites_;
  std::map<std::string, std::unique_ptr<Music>> musics_;
  std::map<std::string, std::unique_ptr<SFX>> sfxs_;
  AverageWindow<double> deltasHistory_;
  std::unique_ptr<InputsHandler> input_handler_;
  std::unique_ptr<SDLContext> sdl_context;

 public:
  int mousePosX = 0;
  int mousePosY = 0;
};

/** @} */

#endif  // WHYCPP_CONTEXT_IMPL_H
