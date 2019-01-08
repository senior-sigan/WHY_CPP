#ifndef WHYCPP_CONTEXT_H
#define WHYCPP_CONTEXT_H

#include <whycpp/video_memory.h>
class Context {
 public:
  explicit Context(VideoMemory &vram) : vram(vram) {}
  virtual ~Context() = default;

  VideoMemory &GetVRAM() {
    return vram;
  }
 private:
  VideoMemory& vram;
};

#endif //WHYCPP_CONTEXT_H
