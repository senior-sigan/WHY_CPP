#include <iostream>
#include <whycpp/application_listener.h>
#include <whycpp/whycpp.h>
#include <whycpp/drawing.h>
#include <whycpp/time.h>
#include <cmath>
#include <vector>
#include <whycpp/color.h>
#include <whycpp/buttons.h>
#include <whycpp/input.h>
#include <whycpp/palette.h>
#include <whycpp/lifecycle.h>
#include <whycpp/text.h>

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

      const RGBA &color = PALETTE[static_cast<int>(GetTime(ctx)) % PALETTE_LEN];
      SetPixel(ctx, x, y, color);
    }
  }
};

class PaletteShow : public ApplicationListener {
 public:
  void OnRender(Context &ctx) override {
    const int w = GetDisplayWidth(ctx) / PALETTE_LEN;
    for (int i = 0; i < PALETTE_LEN; i++) {
      DrawRectFill(ctx, i * w, 0, w, GetDisplayHeight(ctx), PALETTE[i]);
    }
  }
};

class RandomLines : public ApplicationListener {
 public:
  void OnRender(Context &ctx) override {
    int x0 = rnd(GetDisplayWidth(ctx));
    int y0 = rnd(GetDisplayHeight(ctx));

    int x1 = rnd(GetDisplayWidth(ctx));
    int y1 = rnd(GetDisplayHeight(ctx));

    const RGBA &color = PALETTE[static_cast<int>(GetTime(ctx)) % PALETTE_LEN];

    DrawLine(ctx, x0, y0, x1, y1, color);
  }
};

class ButtonsTest : public ApplicationListener {
 public:
  void OnRender(Context &ctx) override {
    DrawClearScreen(ctx, PALETTE[0]);
    Print(ctx, "Press Arrows\nPress Space to exit", 1,10, PALETTE[3], 2);
    if (IsPressed(ctx, Button::KEY_UP)) {
      DrawClearScreen(ctx, PALETTE[1]);
    }
    if (IsPressed(ctx, Button::KEY_DOWN)) {
      DrawClearScreen(ctx, PALETTE[2]);
    }
    if (IsPressed(ctx, Button::KEY_LEFT)) {
      DrawClearScreen(ctx, PALETTE[3]);
    }
    if (IsPressed(ctx, Button::KEY_RIGHT)) {
      DrawClearScreen(ctx, PALETTE[4]);
    }
    if (IsPressed(ctx, Button::KEY_SPACE)) {
      ExitApp(ctx);
    }
  }
};

class HelloText : public ApplicationListener {
 public:
  void OnCreate(Context &ctx) override {
    DrawClearScreen(ctx, PALETTE[0]);
    Print(ctx, 'H', 10, 10, PALETTE[2]);
    Print(ctx, 'H', 10, 20, PALETTE[2], 2);
    Print(ctx, "Hello World", 10, 40, PALETTE[3], 2);
  }
};

class Bubbles: public ApplicationListener {
 public:
  void OnCreate(Context &ctx) override {
    DrawClearScreen(ctx, PALETTE[0]);
    DrawCircle(ctx, 10, 10, 5, PALETTE[2]);
    DrawCircleFill(ctx, 20, 20, 7, PALETTE[3]);
    DrawCircle(ctx, 20, 20, 8, PALETTE[4]);
  }
};

int main(int argc, char *argv[]) {
  RunApp<Bubbles>();
  RunApp<HelloText>();
  RunApp<ButtonsTest>();
  RunApp<PaletteShow>();
  RunApp<Fade>();
  RunApp<Prisma>();
  RunApp<ChessBoard>();
  RunApp<RandomLines>();

  return 0;
}