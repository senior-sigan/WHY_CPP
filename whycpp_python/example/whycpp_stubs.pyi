PALETTE_LEN: int = ...

def get_display_width() -> int: ...


def get_display_height() -> int: ...


def PALETTE(id: int) -> int: ...


def num_as_rgba(color: int) -> (int, int, int, int): ...


def rgba_as_num(red: int, green: int, blue: int, alpha: int) -> int: ...


def set_pixel(x: int, y: int, color: int): ...


def get_pixel(x: int, y: int) -> int: ...


def draw_clear_screen(color: int): ...


def draw_line(x0: int, y0: int, x1: int, y1: int, color: int): ...


def draw_rect_fill(x: int, y: int, w: int, h: int, color: int): ...


def draw_rect(x: int, y: int, w: int, h: int, color: int): ...


def draw_circle(x: int, y: int, radius: int, color: int): ...


def draw_circle_fill(x: int, y: int, radius: int, color: int): ...


def draw_sprite(sprite_id: int, screen_x: int, screen_y: int, sheet_x: int, sheet_y: int, width: int, height: int): ...


def get_delta() -> float: ...


def get_time() -> float: ...


def print(text: str, x: int, y: int, color: int, size: int, spacing: int): ...


def import_sprite(file_name: str) -> int: ...


def log_info(text: str): ...


def is_pressed(): ...


def is_clicked(): ...


def get_mouse(): ...
