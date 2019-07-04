#include "video_memory_holder.h"
#include <whycpp/color.h>
#include <whycpp/types.h>
#include <algorithm>
#include "../int_utils.h"
#include "../logger.h"

union RGBA_flatten {
  RGBA rgba_;
  uint32_t value;
};

union RGBA_unflatten {
  uint32_t value;
  RGBA rgba_;
};

uint32_t FlattenRGBA(const RGBA& rgba) {
  return RGBA_flatten{rgba}.value;
}

VideoMemoryHolder::VideoMemoryHolder(i32 width, i32 height)
    : width(width), height(height), buffer(std::make_unique<uint32_t[]>(AsSize(width * height))) {
  LOG_DEBUG("VideoMemoryHolder [%d, %d] created", width, height);
}
VideoMemoryHolder::~VideoMemoryHolder() {
  LOG_DEBUG("VideoMemoryHolder [%d, %d] destroyed", width, height);
}
void VideoMemoryHolder::Set(i32 x, i32 y, const RGBA& color) {
  auto index = CheckY(y) * AsSize(width) + CheckX(x);
  buffer[index] = RGBA_flatten{color}.value;
}
const RGBA VideoMemoryHolder::Get(i32 x, i32 y) const {
  auto index = CheckY(y) * AsSize(width) + CheckX(x);
  return RGBA_unflatten{buffer[index]}.rgba_;
}
i32 VideoMemoryHolder::GetHeight() const {
  return height;
}
i32 VideoMemoryHolder::GetWidth() const {
  return width;
}
size_t VideoMemoryHolder::CheckX(i32 x) const {
  if (x >= width || x < 0) {
    LOG_VERBOSE("VideoMemoryHolder:  X is out of bound, should be [0, %d) but %d", width, x);
    return AsSize(clamp(x, 0, width - 1));
  }
  return AsSize(x);
}
size_t VideoMemoryHolder::CheckY(i32 y) const {
  if (y >= height || y < 0) {
    LOG_VERBOSE("VideoMemoryHolder:  Y is out of bound, should be [0, %d) but %d", height, y);
    return AsSize(clamp(y, 0, height - 1));
  }
  return AsSize(y);
}
i32 VideoMemoryHolder::GetScreenWidth() const {
  return screen_width;
}
void VideoMemoryHolder::SetScreenWidth(i32 screen_width_) {
  if (screen_width_ < 1) return;
  screen_width = screen_width_;
}
i32 VideoMemoryHolder::GetScreenHeight() const {
  return screen_height;
}
void VideoMemoryHolder::SetScreenHeight(i32 screen_height_) {
  if (screen_height_ < 1) return;
  screen_height = screen_height_;
}
const uint8_t* VideoMemoryHolder::GetBuffer() const {
  return reinterpret_cast<uint8_t*>(buffer.get());
}

void VideoMemoryHolder::Fill(const RGBA& color) {
  auto len = AsSize(width * height);
  uint64_t col = RGBA_flatten{color}.value;
  uint64_t col2 = (col << 32u) | col;
  auto buf = reinterpret_cast<uint64_t*>(buffer.get());
  for (size_t i = 0; i < len / 2; i++) {
    buf[i] = col2;
  }
}
