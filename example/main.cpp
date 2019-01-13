#include <iostream>
#include <whycpp/application_listener.h>
#include <whycpp/whycpp.h>
#include <whycpp/drawing.h>
#include <whycpp/time.h>
#include <math.h>
#include <vector>
#include <whycpp/color.h>

const int PALETTE_LEN = 16;
const RGBA PALETTE[PALETTE_LEN] = {
    RGBA{0, 0, 0, 0},
    RGBA{29, 43, 83, 0},
    RGBA{126, 37, 83, 0},
    RGBA{0, 135, 81, 0},
    RGBA{171, 82, 54, 0},
    RGBA{95, 87, 79, 0},
    RGBA{194, 195, 199, 0},
    RGBA{255, 241, 232, 0},
    RGBA{255, 0, 77, 0},
    RGBA{255, 163, 0, 0},
    RGBA{255, 240, 36, 0},
    RGBA{0, 231, 86, 0},
    RGBA{41, 173, 255, 0},
    RGBA{131, 118, 156, 0},
    RGBA{255, 119, 168, 0},
    RGBA{255, 204, 170, 0}
};

int rnd(int bound) {
  return rand() % bound;
}

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

class Prisma : public ApplicationListener {
 public:
  void OnRender(Context &ctx) override {
    const int base = 143;
    const double pi8 = M_PI / 8;
    const double pi2 = M_PI * 2;
    DrawClearScreen(ctx);
    static double t = 0;

    const RGBA red = {255, 0, 0, 0};
    const RGBA green = {0, 255, 0, 0};
    const RGBA blue = {0, 0, 255, 0};

    for (double i = fmod(t, 8.0); i < base; i += 8.0) {
      DrawLine(ctx, static_cast<int>(i), 0, 0, static_cast<int>(base - i), red);
      DrawLine(ctx, static_cast<int>(i), base, base, static_cast<int>(135 - i), green);
      t += 0.005;
    }

    for (double i = fmod(t / 16, pi8); i < pi2; i += pi8) {
      int x = static_cast<int>(base / 2.0 + (base / 4.0) * cos(i));
      int y = static_cast<int>(base / 2.0 + (base / 4.0) * cos(i));
      DrawLine(ctx, base, 0, x, y, blue);
      DrawLine(ctx, 0, base, x, y, blue);
    }

    DrawLine(ctx, 0, 0, base, 0, red);
    DrawLine(ctx, 0, 0, 0, base, red);
    DrawLine(ctx, base, 0, base, base, green);
    DrawLine(ctx, 0, base, base, base, green);
  }
};

class Fade : public ApplicationListener {
 public:
  void OnRender(Context &ctx) override {
    for (int i = 0; i < 2000; i++) {
      int x = rnd(GetDisplayWidth(ctx));
      int y = rnd(GetDisplayHeight(ctx));

      const RGBA& color = PALETTE[static_cast<int>(GetTime(ctx)) % PALETTE_LEN];
      SetPixel(ctx, x, y, color);
    }
  }
};

class PaletteShow: public ApplicationListener {
 public:
  void OnRender(Context &ctx) override {
    const int w = GetDisplayWidth(ctx) / PALETTE_LEN;
    for (int i = 0; i < PALETTE_LEN; i++) {
      DrawRectFill(ctx, i * w, 0, w, GetDisplayHeight(ctx), PALETTE[i]);
    }
  }
};

class RandomLines: public ApplicationListener {
 public:
  void OnRender(Context &ctx) override {
    int x0 = rnd(GetDisplayWidth(ctx));
    int y0 = rnd(GetDisplayHeight(ctx));

    int x1 = rnd(GetDisplayWidth(ctx));
    int y1 = rnd(GetDisplayHeight(ctx));

    const RGBA& color = PALETTE[static_cast<int>(GetTime(ctx)) % PALETTE_LEN];

    DrawLine(ctx, x0, y0, x1, y1, color);
  }
};

int main(int argc, char *argv[]) {
  RunApp<PaletteShow>();
  RunApp<Fade>();
  RunApp<Prisma>();
  RunApp<ChessBoard>();
  RunApp<RandomLines>();

  return 0;
}