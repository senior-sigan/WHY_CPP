#include <iostream>
#include <whycpp/application_listener.h>
#include <whycpp/application.h>

class Game: public ApplicationListener {
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
  void OnRender(Context& ctx) override {
    for (int x = 0; x < ctx.GetVRAM().GetWidth(); x++) {
      for (int y = 0; y < ctx.GetVRAM().GetHeight(); y++) {
        if (x % 2 == 0 && y % 2 == 0) {
          ctx.GetVRAM().Set(x, y, {0, 0, 0, 0});
        } else {
          ctx.GetVRAM().Set(x, y, {255, 255, 255, 0});
        }
      }
    }
  }
};

int main() {
  Game game;
  Application app(&game);
  app.Run();
  return 0;
}