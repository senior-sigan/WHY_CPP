//
// Created by k.leyfer on 27.03.2019.
//

#include <malloc.h>
#include <stdbool.h>
#include <stdio.h>

#include <whycpp_c/application_config.h>
#include <whycpp_c/application_listener.h>
#include <whycpp_c/whycpp_c.h>

void OnCreate(Context_t* context) {
  printf("%s reporting!\n", __FUNCTION__);
}

void OnResume(Context_t* context) {
  printf("%s reporting!\n", __FUNCTION__);
}

void OnRender(Context_t* context) {
  printf("%s reporting!\n", __FUNCTION__);
}

void OnPause(Context_t* context) {
  printf("%s reporting!\n", __FUNCTION__);
}

void OnDispose(Context_t* context) {
  printf("%s reporting!\n", __FUNCTION__);
}

int main() {
  ApplicationConfig_t config = {
      .width = 256, .height = 144, .name = "Test C API", .is_fullscreen = 0, .window_size_multiplier = 3, .ms_per_frame = 16};

  ApplicationListener_t listener = {
      .onCreate = OnCreate, .onResume = OnResume, .onRender = OnRender, .onPause = OnPause, .onDispose = OnDispose};

  Run(&listener, &config);

  return 0;
}
