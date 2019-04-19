function ButtonsScene() {
}

ButtonsScene.prototype.onRender = function () {
    draw_clear_screen(PALETTE[0]);
    show_text("Press Arrows\nPress Space to exit", 1, 10, PALETTE[3], 2, 1);
    if (is_pressed(KEY_UP)) draw_clear_screen(PALETTE[1]);

    if (is_pressed(KEY_DOWN)) draw_clear_screen(PALETTE[2]);

    if (is_pressed(KEY_LEFT)) draw_clear_screen(PALETTE[3]);

    if (is_pressed(KEY_RIGHT)) draw_clear_screen(PALETTE[4]);
};
ButtonsScene.prototype.onCreate = function () {};
ButtonsScene.prototype.onDispose = function () {};

module.exports = ButtonsScene;