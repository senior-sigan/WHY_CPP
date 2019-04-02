//
// Created by k.leyfer on 27.03.2019.
//

#include <malloc.h>
#include <stdbool.h>
#include <stdio.h>

#include <whycpp_c/application_config.h>
#include <whycpp_c/application_listener.h>
#include <whycpp_c/drawing.h>
#include <whycpp_c/log.h>
#include <whycpp_c/palette.h>
#include <whycpp_c/text.h>
#include <whycpp_c/whycpp_c.h>

void OnCreate() {
  LOG_DEBUG("%s reporting!\n", __FUNCTION__);
}

void OnResume() {
  LOG_DEBUG("%s reporting!\n", __FUNCTION__);
}

void OnRender() {
  LOG_DEBUG("%s reporting! Width: %d, height: %d\n", __FUNCTION__, GetDisplayWidth_C(), GetDisplayHeight_C());
  const int wd = GetDisplayWidth_C();
  const int w = wd / PALETTE_LEN;
  int i = 0;
  for (; i < PALETTE_LEN; i++) {
    DrawRectFill_C(i * w, 0, w, GetDisplayHeight_C(), PALETTE[i]);
  }

  PrintStr_C("Hello there!", 20, 50, PALETTE[0], 3, 4);
}

void OnPause() {
  LOG_DEBUG("%s reporting!\n", __FUNCTION__);
}

void OnDispose() {
  LOG_DEBUG("%s reporting!\n", __FUNCTION__);
}

int main() {
  ApplicationConfig_t config = {.width = 256,
                                .height = 144,
                                .name = "Test C API",
                                .is_fullscreen = 0,
                                .window_size_multiplier = 3,
                                .ms_per_frame = 16};

  ApplicationListener_t listener = {
      .onCreate = OnCreate, .onResume = OnResume, .onRender = OnRender, .onPause = OnPause, .onDispose = OnDispose};

  Run(&listener, &config);

  return 0;
}
