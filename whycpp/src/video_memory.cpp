#include "video_memory.h"
#include <whycpp/color.h>
#include <algorithm>
#include "int_utils.h"
#include "logger.h"

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

VideoMemory::VideoMemory(int width, int height)
    : width(width), height(height), buffer(std::make_unique<uint32_t[]>(AsSize(width * height))) {
  LOG_DEBUG("VideoMemory [%d, %d] created", width, height);
}
VideoMemory::~VideoMemory() {
  LOG_DEBUG("VideoMemory [%d, %d] destroyed", width, height);
}
void VideoMemory::Set(int x, int y, const RGBA& color) {
  auto index = CheckY(y) * AsSize(width) + CheckX(x);
  buffer[index] = RGBA_flatten{color}.value;
}
const RGBA VideoMemory::Get(int x, int y) const {
  auto index = CheckY(y) * AsSize(width) + CheckX(x);
  return RGBA_unflatten{buffer[index]}.rgba_;
}
int VideoMemory::GetHeight() const {
  return height;
}
int VideoMemory::GetWidth() const {
  return width;
}
size_t VideoMemory::CheckX(int x) const {
  if (x >= width || x < 0) {
    LOG_VERBOSE("VideoMemory:  X is out of bound, should be [0, %d) but %d", width, x);
    return AsSize(clamp(x, 0, width - 1));
  }
  return AsSize(x);
}
size_t VideoMemory::CheckY(int y) const {
  if (y >= height || y < 0) {
    LOG_VERBOSE("VideoMemory:  Y is out of bound, should be [0, %d) but %d", height, y);
    return AsSize(clamp(y, 0, height - 1));
  }
  return AsSize(y);
}
int VideoMemory::GetScreenWidth() const {
  return screen_width;
}
void VideoMemory::SetScreenWidth(int screen_width_) {
  if (screen_width_ < 1) return;
  screen_width = screen_width_;
}
int VideoMemory::GetScreenHeight() const {
  return screen_height;
}
void VideoMemory::SetScreenHeight(int screen_height_) {
  if (screen_height_ < 1) return;
  screen_height = screen_height_;
}
const uint8_t* VideoMemory::GetBuffer() const {
  return reinterpret_cast<uint8_t*>(buffer.get());
}

void VideoMemory::Fill(const RGBA& color) {
  auto len = AsSize(width * height);
  uint64_t col = RGBA_flatten{color}.value;
  uint64_t col2 = (col << 32u) | col;
  auto buf = reinterpret_cast<uint64_t*>(buffer.get());
  for (size_t i = 0; i < len / 2; i++) {
    buf[i] = col2;
  }
}
