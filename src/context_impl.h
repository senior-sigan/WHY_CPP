#ifndef WHYCPP_CONTEXT_IMPL_H
#define WHYCPP_CONTEXT_IMPL_H

#include "video_memory.h"

class Context {
 public:
  explicit Context(VideoMemory &vram) : vram(vram) {}
  virtual ~Context() = default;

  VideoMemory &GetVRAM() const {
    return vram;
  }
 private:
  VideoMemory& vram;
};

#endif //WHYCPP_CONTEXT_IMPL_H
