import whycpp
from random import randint
import math


class IScene:
    def on_render(self):
        pass

    def on_dispose(self):
        pass

    def on_create(self):
        pass


class Fade(IScene):
    def on_create(self):
        whycpp.draw_clear_screen(whycpp.PALETTE(0))

    def on_render(self):
        for i in range(0, 2000):
            x = randint(0, whycpp.get_display_width())
            y = randint(0, whycpp.get_display_height())
            i = int(whycpp.get_time() % whycpp.PALETTE_LEN)
            whycpp.set_pixel(x, y, whycpp.PALETTE(i))


class PaletteShow(IScene):
    def on_render(self):
        w = whycpp.get_display_width() / whycpp.PALETTE_LEN
        h = whycpp.get_display_height()
        for i in range(0, whycpp.PALETTE_LEN):
            whycpp.draw_rect_fill(i * w, 0, w, h, whycpp.PALETTE(i))


class RandomLines(IScene):
    def on_create(self):
        whycpp.draw_clear_screen(whycpp.PALETTE(0))

    def on_render(self):
        w = whycpp.get_display_width()
        h = whycpp.get_display_height()

        x0 = randint(0, w)
        x1 = randint(0, w)
        y0 = randint(0, h)
        y1 = randint(0, h)

        i = int(whycpp.get_time() % whycpp.PALETTE_LEN)

        whycpp.draw_line(x0, y0, x1, y1, whycpp.PALETTE(i))


class ButtonsTest(IScene):
    def on_render(self):
        whycpp.draw_clear_screen(whycpp.PALETTE(0))
        whycpp.print("Press Arrows\nPress Space to exit", 1, 10, whycpp.PALETTE(3), 2, 1)

        if whycpp.is_pressed(whycpp.KEY_UP):
            whycpp.draw_clear_screen(whycpp.PALETTE(1))

        if whycpp.is_pressed(whycpp.KEY_DOWN):
            whycpp.draw_clear_screen(whycpp.PALETTE(2))

        if whycpp.is_pressed(whycpp.KEY_LEFT):
            whycpp.draw_clear_screen(whycpp.PALETTE(3))

        if whycpp.is_pressed(whycpp.KEY_RIGHT):
            whycpp.draw_clear_screen(whycpp.PALETTE(4))


class HelloText(IScene):
    def on_render(self):
        whycpp.draw_clear_screen(whycpp.PALETTE(0))
        whycpp.print("WhyCPP\nHello World", 10, 40, whycpp.PALETTE(3), 2, 0)
        whycpp.print("JOU\rTEA", 10, 80, whycpp.PALETTE(4), 2, 0)


class MouseTest(IScene):
    def on_render(self):
        x, y = whycpp.get_mouse()
        if whycpp.is_pressed(whycpp.MOUSE_BUTTON_LEFT):
            whycpp.draw_circle_fill(x, y, 2, whycpp.PALETTE(3))
        elif (whycpp.is_pressed(whycpp.MOUSE_BUTTON_RIGHT)):
            whycpp.draw_circle_fill(x, y, 2, whycpp.PALETTE(4))
        else:
            whycpp.draw_circle_fill(x, y, 2, whycpp.PALETTE(5))


class Bubbles(IScene):
    def on_render(self):
        whycpp.draw_clear_screen(whycpp.PALETTE(0))
        whycpp.draw_circle(10, 10, 5, whycpp.PALETTE(2))
        whycpp.draw_circle_fill(20, 20, 7, whycpp.PALETTE(3))
        whycpp.draw_circle(20, 20, 8, whycpp.PALETTE(4))


class Prisma(IScene):
    def __init__(self) -> None:
        self.t = 0

    def on_render(self):
        whycpp.draw_clear_screen(whycpp.PALETTE(0))
        base = 143.0
        pi8 = math.pi / 8.0
        pi2 = math.pi * 2.0

        red = whycpp.PALETTE(8)
        green = whycpp.PALETTE(11)
        blue = whycpp.PALETTE(12)

        i = math.fmod(self.t, 8.0)
        while i < base:
            x = int(i)
            y = int(base - i)
            whycpp.draw_line(x, 0, 0, y, red)
            whycpp.draw_line(x, base, base, y, green)
            self.t += whycpp.get_delta()
            i += 8.0

        i = math.fmod(self.t / 16, pi8)
        while i < pi2:
            x = int(base / 2.0 + (base / 4.0) * math.cos(i))
            y = int(base / 2.0 + (base / 4.0) * math.cos(i))
            whycpp.draw_line(base, 0, x, y, blue)
            whycpp.draw_line(0, base, x, y, blue)
            i += pi8

        whycpp.draw_line(0, 0, base, 0, red)
        whycpp.draw_line(0, 0, 0, base, red)
        whycpp.draw_line(base, 0, base, base, green)
        whycpp.draw_line(0, base, base, base, green)


class Game(IScene):
    def __init__(self):
        self.scenes = [
            Prisma(),
            PaletteShow(),
            MouseTest(),
            ButtonsTest(),
            HelloText(),
            Bubbles(),
            Fade(),
            RandomLines()
        ]
        self.current_scene = 0
        self.prev_scene = len(self.scenes)

    def on_render(self):
        if self.prev_scene != self.current_scene:
            if self.prev_scene != len(self.scenes):
                self.scenes[self.prev_scene].on_dispose()
            self.scenes[self.current_scene].on_create()
            self.prev_scene = self.current_scene
        self.scenes[self.current_scene].on_render()

        if whycpp.is_clicked(whycpp.KEY_SPACE):
            self.current_scene = (self.current_scene + 1) % len(self.scenes)
        if whycpp.is_clicked(whycpp.KEY_ESCAPE):
            whycpp.exit()


game: Game


def on_create():
    global game
    game = Game()
    game.on_create()


def on_render():
    game.on_render()


def on_pause():
    pass


def on_resume():
    pass


def on_dispose():
    print("OnDispose")
