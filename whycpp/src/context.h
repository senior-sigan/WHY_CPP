#pragma once

#include <whycpp/application_config.h>
#include <whycpp/buttons.h>
#include <whycpp/types.h>
#include <map>
#include <memory>
#include <string>
#include <vector>
#include "average_window.h"

class Font;
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
  explicit Context(VideoMemory *vram, Font *font, const ApplicationConfig &config);
  virtual ~Context();

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
  Font *GetFont() const;
  void SetFont(Font *font);
  i32 AppendSprite(Sprite *sprite);
  Sprite *GetSprite(i32 index) const;

  void RegisterMusic(const std::string &path, const std::string &name);
  Music *GetMusic(const std::string &name) const;
  void RegisterSFX(const std::string &path, const std::string &name);
  SFX *GetSFX(const std::string &name) const;

  void Tick(double delta);
  void SetRealDeltaTime(double delta);
  void KeyUp(u32 code);
  void KeyDown(u32 code);
  void ResetKeys();
  i32 GetFPS() const;

 private:
  std::unique_ptr<VideoMemory> vram_;
  const ApplicationConfig config_;
  double time_ = 0.0;
  double current_delta_ = 0.0;
  std::vector<bool> buttons_;
  std::vector<bool> clicked_;
  bool quit_ = false;
  bool paused_ = false;
  std::unique_ptr<Font> font_;
  std::vector<std::unique_ptr<Sprite>> sprites_;
  std::map<std::string, std::unique_ptr<Music>> musics_;
  std::map<std::string, std::unique_ptr<SFX>> sfxs_;
  AverageWindow<double> deltasHistory_;

 public:
  i32 mousePosX = 0;
  i32 mousePosY = 0;
};

/** @} */
