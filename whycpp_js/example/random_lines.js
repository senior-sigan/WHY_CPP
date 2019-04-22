function randint(min_, max_) {
    return (Math.random() * max_ + min_) >> 0;
}

function RandomLinesScene() {
}

RandomLinesScene.prototype.onCreate = function () {
    draw_clear_screen(PALETTE[0]);
};
RandomLinesScene.prototype.onRender = function () {
    var w = get_display_width();
    var h = get_display_height();

    var x0 = randint(0, w);
    var x1 = randint(0, w);
    var y0 = randint(0, h);
    var y1 = randint(0, h);

    var i = (get_time() % PALETTE_LEN) >> 0;

    draw_line(x0, y0, x1, y1, PALETTE[i]);
};
RandomLinesScene.prototype.onDispose = function () {
};

module.exports = RandomLinesScene;