#include <iostream>
#include <whycpp/application_listener.h>
#include <whycpp/whycpp.h>
#include <whycpp/drawing.h>

class Game : public ApplicationListener {
 public:
  void OnCreate() override {
    std::cout << "OnCreate" << std::endl;
  }
  void OnDispose() override {
    std::cout << "OnDispose" << std::endl;
  }
  void OnPause() override {
    std::cout << "OnPause" << std::endl;
  }
  void OnRender(Context &ctx) override {
    for (int x = 0; x < GetDisplayWidth(ctx); x++) {
      for (int y = 0; y < GetDisplayHeight(ctx); y++) {
        if (x % 2 == 0 && y % 2 == 0) {
          SetPixel(ctx, x, y, {0, 0, 0, 0});
        } else {
          SetPixel(ctx, x, y, {255, 255, 255, 0});
        }
      }
    }
  }
};

int main(int argc, char *argv[]) {
  Game game;
  Run(&game);
  return 0;
}