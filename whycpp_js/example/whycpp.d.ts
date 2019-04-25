declare function draw_clear_screen(color: number[]): void;

declare function get_display_width(): number;

declare function get_display_height(): number;

declare function set_pixel(x: number, y: number, color: number[]): void;

declare function get_pixel(x: number, y: number): number;

declare function draw_line(x0: number, y0: number, x1: number, y1: number, color: number[]): void;

declare function draw_rect_fill(x: number, y: number, w: number, h: number, color: number[]): void;

declare function draw_rect(x: number, y: number, w: number, h: number, color: number[]): void;

declare function draw_circle(x: number, y: number, radius: number, color: number[]): void;

declare function draw_circle_fill(x: number, y: number, radius: number, color: number[]): void;

declare function draw_sprite(sprite_id: number, screen_x: number, screen_y: number, sheet_x: number, sheet_y: number, width: number, height: number): void;

declare function get_delta(): number;

declare function get_time(): number;

declare function show_text(text: string, x: number, y: number, color: number[], size: number, spacing: number): void;

declare function import_sprite(file_name: string): number;

declare function print(text: string): void;

declare function is_pressed(btn: number): boolean;

declare function is_clicked(btn: number): boolean;

declare function get_mouse(): { x: number, y: number };

declare function exit(): void;

declare function importMusic(path: string, name: string): void;

declare function importSFX(path: string, name: string): void;

declare function playMusic(name: string, loop: number): void;

declare function playSFX(name: string, loop: number, ticks: number): void;

declare const PALETTE_LEN: number;
declare const PALETTE: number[][];

declare const KEY_A: number;
declare const KEY_B: number;
declare const KEY_C: number;
declare const KEY_D: number;
declare const KEY_E: number;
declare const KEY_F: number;
declare const KEY_G: number;
declare const KEY_H: number;
declare const KEY_I: number;
declare const KEY_J: number;
declare const KEY_K: number;
declare const KEY_L: number;
declare const KEY_M: number;
declare const KEY_N: number;
declare const KEY_O: number;
declare const KEY_P: number;
declare const KEY_Q: number;
declare const KEY_R: number;
declare const KEY_S: number;
declare const KEY_T: number;
declare const KEY_U: number;
declare const KEY_V: number;
declare const KEY_W: number;
declare const KEY_X: number;
declare const KEY_Y: number;
declare const KEY_Z: number;
declare const KEY_1: number;
declare const KEY_2: number;
declare const KEY_3: number;
declare const KEY_4: number;
declare const KEY_5: number;
declare const KEY_6: number;
declare const KEY_7: number;
declare const KEY_8: number;
declare const KEY_9: number;
declare const KEY_0: number;
declare const KEY_RETURN: number;
declare const KEY_ESCAPE: number;
declare const KEY_BACKSPACE: number;
declare const KEY_TAB: number;
declare const KEY_SPACE: number;
declare const KEY_F1: number;
declare const KEY_F2: number;
declare const KEY_F3: number;
declare const KEY_F4: number;
declare const KEY_F5: number;
declare const KEY_F6: number;
declare const KEY_F7: number;
declare const KEY_F8: number;
declare const KEY_F9: number;
declare const KEY_F10: number;
declare const KEY_F11: number;
declare const KEY_F12: number;
declare const KEY_RIGHT: number;
declare const KEY_LEFT: number;
declare const KEY_DOWN: number;
declare const KEY_UP: number;
declare const KEY_LCTRL: number;
declare const KEY_LSHIFT: number;
declare const KEY_LALT: number;
declare const KEY_RCTRL: number;
declare const KEY_RSHIFT: number;
declare const KEY_RALT: number;
declare const MOUSE_BUTTON_LEFT: number;
declare const MOUSE_BUTTON_MIDDLE: number;
declare const MOUSE_BUTTON_RIGHT: number;