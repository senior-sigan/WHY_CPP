function MouseScene() {
}

MouseScene.prototype.onRender = function () {
    var p = get_mouse();
    if (is_pressed(MOUSE_BUTTON_LEFT)) {
        draw_circle_fill(p.x, p.y, 2, PALETTE[3]);
    } else if (is_pressed(MOUSE_BUTTON_RIGHT)) {
        draw_circle_fill(p.x, p.y, 2, PALETTE[4]);
    } else {
        draw_circle_fill(p.x, p.y, 2, PALETTE[5]);
    }
};

MouseScene.prototype.onCreate = function () {
};
MouseScene.prototype.onDispose = function () {
};

module.exports = MouseScene;