var CONFIG = {
    'width': 256,
    'height': 144,
    'name': 'JS Application',
    'is_fullscreen': false,
    'window_size_multiplier': 3,
    'ms_per_frame': 16
};

function onRender() {
    var w = get_display_width() / PALETTE_LEN;
    var h = get_display_height();
    for (var i = 0; i < PALETTE_LEN; i++) {
        draw_rect_fill(i * w, 0, w, h, PALETTE[i]);
    }
}

function onCreate() {
    print("onCreate");
}

function onDispose() {
    print("onDispose");
}