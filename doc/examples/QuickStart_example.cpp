#include <whycpp/application_listener.h>
#include <whycpp/whycpp.h>
#include <whycpp/drawing.h>

class ChessBoard : public ApplicationListener {
 public:
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
  RunApp<ChessBoard>();

  return 0;
}