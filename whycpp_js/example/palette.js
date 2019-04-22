function PaletteScene() {
}

PaletteScene.prototype.onRender = function () {
    var w = get_display_width() / PALETTE_LEN;
    var h = get_display_height();
    for (var i = 0; i < PALETTE_LEN; i++) {
        draw_rect_fill(i * w, 0, w, h, PALETTE[i]);
    }
};
PaletteScene.prototype.onCreate = function () {
};
PaletteScene.prototype.onDispose = function () {
};

module.exports = PaletteScene;