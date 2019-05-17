#include <whycpp/animation.h>
#include <whycpp/application_listener.h>
#include <whycpp/buttons.h>
#include <whycpp/color.h>
#include <whycpp/drawing.h>
#include <whycpp/import_sprites.h>
#include <whycpp/input.h>
#include <whycpp/lifecycle.h>
#include <whycpp/log.h>
#include <whycpp/palette.h>
#include <whycpp/sound.h>
#include <whycpp/text.h>
#include <whycpp/time.h>
#include <whycpp/whycpp.h>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <sstream>
#include <vector>

class TrueRandom {
 public:
  TrueRandom() {
    std::srand(static_cast<unsigned int>(std::time(nullptr)));
  }

  int NextInt(int min, int max) const {
    if (min == max) return min;
    // there is a problem in MinGW implementation of random. So use old school rand.
    // A notable implementation where std::random_device is deterministic is MinGW (bug 338),
    // although replacement implementations exist, such as mingw-std-random_device.
    return std::rand() % (max - min) + min;
  }

  int Bound(int max) const {
    return NextInt(0, max);
  }
};

class ChessBoard : public ApplicationListener {
 public:
  void OnRender(Context &ctx) override {
    for (int x = 0; x < GetDisplayWidth(ctx); x++) {
      for (int y = 0; y < GetDisplayHeight(ctx); y++) {
        if (x % 2 == 0 && y % 2 == 0) {
          SetPixel(ctx, x, y, {0, 0, 0, 255});
        } else {
          SetPixel(ctx, x, y, {255, 255, 255, 255});
        }
      }
    }
  }
};

class Prisma : public ApplicationListener {
  const double PI = 3.14159265358979323846;

 public:
  void OnRender(Context &ctx) override {
    const int base = 143;
    const double pi8 = PI / 8;
    const double pi2 = PI * 2;
    DrawClearScreen(ctx);
    static double t = 0;

    const RGBA red = {255, 0, 0, 255};
    const RGBA green = {0, 255, 0, 255};
    const RGBA blue = {0, 0, 255, 255};

    for (double i = fmod(t, 8.0); i < base; i += 8.0) {
      int x = static_cast<int>(i);
      int y = static_cast<int>(base - i);
      DrawLine(ctx, x, 0, 0, y, red);
      DrawLine(ctx, x, base, base, y, green);
      t += GetDelta(ctx);
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
  TrueRandom rnd;

 public:
  void OnCreate(Context &ctx) override {
    DrawClearScreen(ctx, PALETTE[0]);
  }

  void OnRender(Context &ctx) override {
    for (int i = 0; i < 2000; i++) {
      int x = rnd.Bound(GetDisplayWidth(ctx));
      int y = rnd.Bound(GetDisplayHeight(ctx));

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
  TrueRandom rnd;

 public:
  void OnCreate(Context &ctx) override {
    DrawClearScreen(ctx, PALETTE[0]);
  }
  void OnRender(Context &ctx) override {
    int x0 = rnd.Bound(GetDisplayWidth(ctx));
    int y0 = rnd.Bound(GetDisplayHeight(ctx));

    int x1 = rnd.Bound(GetDisplayWidth(ctx));
    int y1 = rnd.Bound(GetDisplayHeight(ctx));

    const RGBA &color = PALETTE[static_cast<int>(GetTime(ctx)) % PALETTE_LEN];

    DrawLine(ctx, x0, y0, x1, y1, color);
  }
};

class ButtonsTest : public ApplicationListener {
 public:
  void OnRender(Context &ctx) override {
    DrawClearScreen(ctx, PALETTE[0]);
    Print(ctx, "Press Arrows\nPress Space to exit", 1, 10, PALETTE[3], 2);
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

class Bubbles : public ApplicationListener {
 public:
  void OnCreate(Context &ctx) override {
    DrawClearScreen(ctx, PALETTE[0]);
    DrawCircle(ctx, 10, 10, 5, PALETTE[2]);
    DrawCircleFill(ctx, 20, 20, 7, PALETTE[3]);
    DrawCircle(ctx, 20, 20, 8, PALETTE[4]);
  }
};

class PngTexture : public ApplicationListener {
  int id = -1;
  std::shared_ptr<Animation> anim;

 public:
  void OnCreate(Context &context) override {
    id = ImportSprite(context, "assets/atlas.png");
    std::vector<std::pair<int, int>> sprites = {
        {20 * 16, 40 * 16}, {21 * 16, 40 * 16}, {22 * 16, 40 * 16}, {23 * 16, 40 * 16}, {24 * 16, 40 * 16},
        {20 * 16, 42 * 16}, {21 * 16, 42 * 16}, {22 * 16, 42 * 16}, {26 * 16, 40 * 16}, {20 * 16, 38 * 16},
        {21 * 16, 38 * 16}, {22 * 16, 38 * 16}, {23 * 16, 38 * 16}, {24 * 16, 38 * 16}, {24 * 16, 38 * 16},
        {26 * 16, 38 * 16}, {27 * 16, 38 * 16}, {28 * 16, 38 * 16}, {29 * 16, 38 * 16}, {30 * 16, 38 * 16},
        {31 * 16, 38 * 16},
    };
    anim = std::make_shared<Animation>(16, 32, 8, sprites, id, true);
  }

  void OnRender(Context &context) override {
    DrawSprite(context, id, 0, 0, 0, 0, GetDisplayWidth(context), GetDisplayHeight(context));
    anim->Draw(context, 32, 32);
    Print(context, "ANIMATION", 8, 64, PALETTE[3]);
  }
};

class MouseTest : public ApplicationListener {
 public:
  void OnRender(Context &ctx) override {
    int x = 0;
    int y = 0;
    GetMouse(ctx, x, y);
    if (IsPressed(ctx, MOUSE_BUTTON_LEFT)) {
      DrawCircleFill(ctx, x, y, 2, PALETTE[3]);
    } else if (IsPressed(ctx, MOUSE_BUTTON_RIGHT)) {
      DrawCircleFill(ctx, x, y, 2, PALETTE[4]);
    } else {
      DrawCircleFill(ctx, x, y, 2, PALETTE[5]);
    }
  }
};

class SoundTest : public ApplicationListener {
 public:
  void OnCreate(Context &ctx) override {
    ImportSFX(ctx, "assets/bonus.wav", "bonus.wav");
    DrawClearScreen(ctx, PALETTE[0]);
    Print(ctx, "Press S\nto hear sound\nPress Space to exit", 1, 10, PALETTE[3], 1);
  }
  void OnRender(Context &ctx) override {
    if (IsClicked(ctx, Button::KEY_S)) {
      PlaySFX(ctx, "bonus.wav");
    }
    if (IsClicked(ctx, Button::KEY_W)) {
      StopSFX(ctx, "bonus.wav");
    }
  }
};

class FpsLogger {
 public:
  void Log(Context &ctx) {
    auto fps = GetFPS(ctx);
    std::stringstream ss;
    ss << "FPS=" << fps << "\nTime=" << static_cast<int>(GetTime(ctx));
    DrawRectFill(ctx, GetDisplayWidth(ctx)-50, 0, 50, 20, PALETTE[0]);
    Print(ctx, ss.str(), GetDisplayWidth(ctx)-50,0, PALETTE[7]);
  }
};

class Show : public ApplicationListener {
  std::vector<std::unique_ptr<ApplicationListener>> apps{};
  size_t current_app = 0;
  size_t prev_app = 0;
  FpsLogger logger{};

 public:
  Show() {
    apps.push_back(std::make_unique<MouseTest>());
    apps.push_back(std::make_unique<Prisma>());
    apps.push_back(std::make_unique<Fade>());
    apps.push_back(std::make_unique<PaletteShow>());
    apps.push_back(std::make_unique<Bubbles>());
    apps.push_back(std::make_unique<HelloText>());
    apps.push_back(std::make_unique<ButtonsTest>());
    apps.push_back(std::make_unique<ChessBoard>());
    apps.push_back(std::make_unique<RandomLines>());
    apps.push_back(std::make_unique<PngTexture>());
    apps.push_back(std::make_unique<SoundTest>());

    prev_app = apps.size();
    current_app = 0;
  }

  void OnRender(Context &ctx) override {
    if (prev_app != current_app) {
      if (prev_app != apps.size()) {
        apps.at(prev_app)->OnDispose(ctx);
      }
      apps.at(current_app)->OnCreate(ctx);
      prev_app = current_app;
    }

    apps.at(current_app)->OnRender(ctx);
    logger.Log(ctx);

    if (IsClicked(ctx, Button::KEY_SPACE)) {
      current_app = (current_app + 1) % apps.size();
    }
    if (IsClicked(ctx, Button::KEY_ESCAPE)) {
      ExitApp(ctx);
    }
  }

  ~Show() override {
    apps.clear();
  }
};

int main() {
  SetLogLevel(LogLevel::DEBUG);
  RunApp<Show>(ApplicationConfig(256, 144, "Application", false, 3, 16, true));
  return 0;
}