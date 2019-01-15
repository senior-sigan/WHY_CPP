#ifndef WHYCPP_CONTEXT_IMPL_H
#define WHYCPP_CONTEXT_IMPL_H

class VideoMemory;
struct SDL_Keysym;

class Context {
 public:
  explicit Context(VideoMemory &vram) : vram(vram) {}
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

  void Tick(double delta);
  void KeyUp(const SDL_Keysym& keysym);
  void KeyDown(const SDL_Keysym& keysym);
 private:
  VideoMemory& vram;
  double time = 0.0;
  double current_delta = 0.0;
};

#endif //WHYCPP_CONTEXT_IMPL_H
