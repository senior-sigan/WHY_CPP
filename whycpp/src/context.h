#ifndef WHYCPP_CONTEXT_IMPL_H
#define WHYCPP_CONTEXT_IMPL_H

#include <map>
#include <memory>
#include <string>
#include <vector>

#include <whycpp/buttons.h>

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
  explicit Context(VideoMemory *vram, Font *font);
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
  int AppendSprite(Sprite *sprite);
  Sprite *GetSprite(int index) const;

  void RegisterMusic(const std::string &path, const std::string &name);
  Music *GetMusic(const std::string &name) const;
  void RegisterSFX(const std::string &path, const std::string &name);
  SFX *GetSFX(const std::string &name) const;

  void Tick(double delta);
  void KeyUp(unsigned int code);
  void KeyDown(unsigned int code);
  void ResetKeys();

 private:
  std::unique_ptr<VideoMemory> vram_;
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

 public:
  int mousePosX = 0;
  int mousePosY = 0;
};

/** @} */

#endif  // WHYCPP_CONTEXT_IMPL_H
