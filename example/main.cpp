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
  void OnRender() override {
    for (int x = 0; x < GetDisplayWidth(); x++) {
      for (int y = 0; y < GetDisplayHeight(); y++) {
        if (x % 2 == 0 && y % 2 == 0) {
          SetPixel(x, y, {0, 0, 0, 255});
        } else {
          SetPixel(x, y, {255, 255, 255, 255});
        }
      }
    }
  }
};

class Prisma : public ApplicationListener {
  const double PI = 3.14159265358979323846;

 public:
  void OnRender() override {
    const int base = 143;
    const double pi8 = PI / 8;
    const double pi2 = PI * 2;
    DrawClearScreen();
    static double t = 0;

    const RGBA red = {255, 0, 0, 255};
    const RGBA green = {0, 255, 0, 255};
    const RGBA blue = {0, 0, 255, 255};

    for (double i = fmod(t, 8.0); i < base; i += 8.0) {
      int x = static_cast<int>(i);
      int y = static_cast<int>(base - i);
      DrawLine(x, 0, 0, y, red);
      DrawLine(x, base, base, y, green);
      t += GetDelta();
    }

    for (double i = fmod(t / 16, pi8); i < pi2; i += pi8) {
      int x = static_cast<int>(base / 2.0 + (base / 4.0) * cos(i));
      int y = static_cast<int>(base / 2.0 + (base / 4.0) * cos(i));
      DrawLine(base, 0, x, y, blue);
      DrawLine(0, base, x, y, blue);
    }

    DrawLine(0, 0, base, 0, red);
    DrawLine(0, 0, 0, base, red);
    DrawLine(base, 0, base, base, green);
    DrawLine(0, base, base, base, green);
  }
};

class Fade : public ApplicationListener {
  TrueRandom rnd;

 public:
  void OnCreate() override {
    DrawClearScreen(PALETTE[0]);
  }

  void OnRender() override {
    for (int i = 0; i < 2000; i++) {
      int x = rnd.Bound(GetDisplayWidth());
      int y = rnd.Bound(GetDisplayHeight());

      const RGBA &color = PALETTE[static_cast<int>(GetTime()) % PALETTE_LEN];
      SetPixel(x, y, color);
    }
  }
};

class PaletteShow : public ApplicationListener {
 public:
  void OnRender() override {
    const int w = GetDisplayWidth() / PALETTE_LEN;
    for (int i = 0; i < PALETTE_LEN; i++) {
      DrawRectFill(i * w, 0, w, GetDisplayHeight(), PALETTE[i]);
    }
  }
};

class RandomLines : public ApplicationListener {
  TrueRandom rnd;

 public:
  void OnCreate() override {
    DrawClearScreen(PALETTE[0]);
  }
  void OnRender() override {
    int x0 = rnd.Bound(GetDisplayWidth());
    int y0 = rnd.Bound(GetDisplayHeight());

    int x1 = rnd.Bound(GetDisplayWidth());
    int y1 = rnd.Bound(GetDisplayHeight());

    const RGBA &color = PALETTE[static_cast<int>(GetTime()) % PALETTE_LEN];

    DrawLine(x0, y0, x1, y1, color);
  }
};

class ButtonsTest : public ApplicationListener {
 public:
  void OnRender() override {
    DrawClearScreen(PALETTE[0]);
    Print("Press Arrows\nPress Space to exit", 1, 10, PALETTE[3], 2);
    if (IsPressed(Button::KEY_UP)) {
      DrawClearScreen(PALETTE[1]);
    }
    if (IsPressed(Button::KEY_DOWN)) {
      DrawClearScreen(PALETTE[2]);
    }
    if (IsPressed(Button::KEY_LEFT)) {
      DrawClearScreen(PALETTE[3]);
    }
    if (IsPressed(Button::KEY_RIGHT)) {
      DrawClearScreen(PALETTE[4]);
    }
  }
};

class HelloText : public ApplicationListener {
 public:
  void OnCreate() override {
    DrawClearScreen(PALETTE[0]);
    Print('H', 10, 10, PALETTE[2]);
    Print('H', 10, 20, PALETTE[2], 2);
    Print("Hello World", 10, 40, PALETTE[3], 2);
  }
};

class Bubbles : public ApplicationListener {
 public:
  void OnCreate() override {
    DrawClearScreen(PALETTE[0]);
    DrawCircle(10, 10, 5, PALETTE[2]);
    DrawCircleFill(20, 20, 7, PALETTE[3]);
    DrawCircle(20, 20, 8, PALETTE[4]);
  }
};

class PngTexture : public ApplicationListener {
  int id = -1;
  std::shared_ptr<Animation> anim;

 public:
  void OnCreate() override {
    id = ImportSprite("assets/atlas.png");
    std::vector<std::pair<int, int>> sprites = {
        {20 * 16, 40 * 16}, {21 * 16, 40 * 16}, {22 * 16, 40 * 16}, {23 * 16, 40 * 16}, {24 * 16, 40 * 16},
        {20 * 16, 42 * 16}, {21 * 16, 42 * 16}, {22 * 16, 42 * 16}, {26 * 16, 40 * 16}, {20 * 16, 38 * 16},
        {21 * 16, 38 * 16}, {22 * 16, 38 * 16}, {23 * 16, 38 * 16}, {24 * 16, 38 * 16}, {24 * 16, 38 * 16},
        {26 * 16, 38 * 16}, {27 * 16, 38 * 16}, {28 * 16, 38 * 16}, {29 * 16, 38 * 16}, {30 * 16, 38 * 16},
        {31 * 16, 38 * 16},
    };
    anim = std::make_shared<Animation>(16, 32, 8, sprites, id, true);
  }

  void OnRender() override {
    DrawSprite(id, 0, 0, 0, 0, GetDisplayWidth(), GetDisplayHeight());
    anim->Draw(32, 32);
    Print("ANIMATION", 8, 64, PALETTE[3]);
  }
};

class MouseTest : public ApplicationListener {
 public:
  void OnRender() override {
    int x = 0;
    int y = 0;
    GetMouse(x, y);
    if (IsPressed(MOUSE_BUTTON_LEFT)) {
      DrawCircleFill(x, y, 2, PALETTE[3]);
    } else if (IsPressed(MOUSE_BUTTON_RIGHT)) {
      DrawCircleFill(x, y, 2, PALETTE[4]);
    } else {
      DrawCircleFill(x, y, 2, PALETTE[5]);
    }
  }
};

class SoundTest : public ApplicationListener {
 public:
  void OnCreate() override {
    ImportSFX("assets/bonus.wav", "bonus.wav");
    DrawClearScreen(PALETTE[0]);
    Print("Press S\nto hear sound\nPress Space to exit", 1, 10, PALETTE[3], 1);
  }
  void OnRender() override {
    if (IsClicked(Button::KEY_S)) {
      PlaySFX("bonus.wav");
    }
    if (IsClicked(Button::KEY_W)) {
      StopSFX("bonus.wav");
    }
  }
};

class FpsLogger {
 public:
  void Log() {
    auto fps = GetFPS();
    std::stringstream ss;
    ss << "FPS=" << fps << "\nTime=" << static_cast<int>(GetTime());
    DrawRectFill(GetDisplayWidth()-50, 0, 50, 20, PALETTE[0]);
    Print(ss.str(), GetDisplayWidth()-50,0, PALETTE[7]);
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

  void OnRender() override {
    if (prev_app != current_app) {
      if (prev_app != apps.size()) {
        apps.at(prev_app)->OnDispose();
      }
      apps.at(current_app)->OnCreate();
      prev_app = current_app;
    }

    apps.at(current_app)->OnRender();
    logger.Log();

    if (IsClicked(Button::KEY_SPACE)) {
      current_app = (current_app + 1) % apps.size();
    }
    if (IsClicked(Button::KEY_ESCAPE)) {
      ExitApp();
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