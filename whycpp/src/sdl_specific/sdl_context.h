#pragma once

#include <memory>

class SDLAudioContext;
class SDLRenderContext;
struct ApplicationConfig;
class VideoMemoryHolder;

class SDLContext {
  std::unique_ptr<SDLRenderContext> render_;
  std::unique_ptr<SDLAudioContext> audio_;

 public:
  SDLContext(const ApplicationConfig& config, VideoMemoryHolder* vram);
  virtual ~SDLContext();
  SDLRenderContext* GetRenderer() const;
};
