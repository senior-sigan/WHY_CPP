var CONFIG = {
    'width': 256,
    'height': 144,
    'name': 'JS Application',
    'is_fullscreen': false,
    'window_size_multiplier': 3,
    'ms_per_frame': 16
};

function randint(min_, max_) {
    return (Math.random() * max_ + min_) >> 0;
}

function IScene() {
}
IScene.prototype.onRender = function () {
    print("IScene.onRender")
};
IScene.prototype.onCreate = function () {
    print("IScene.onCreate")
};
IScene.prototype.onDispose = function () {
    print("IScene.onDispose")
};

function PaletteScene() {
}
PaletteScene.prototype = new IScene();
PaletteScene.prototype.onRender = function () {
    var w = get_display_width() / PALETTE_LEN;
    var h = get_display_height();
    for (var i = 0; i < PALETTE_LEN; i++) {
        draw_rect_fill(i * w, 0, w, h, PALETTE[i]);
    }
};

function RandomLinesScene() {}
RandomLinesScene.prototype = new IScene();
RandomLinesScene.prototype.onCreate = function() {
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


function SceneManager() {
    this.scenes = [
        new PaletteScene(),
        new RandomLinesScene()
    ];
    this.currentScene = 0;
    this.prevScene = this.scenes.length;
}

SceneManager.prototype.onRender = function () {
    if (this.prevScene !== this.currentScene) {
        if (this.prevScene !== this.scenes.length) {
            this.scenes[this.prevScene].onDispose();
        }
        this.scenes[this.currentScene].onCreate();
        this.prevScene = this.currentScene;
    }
    this.scenes[this.currentScene].onRender();

    if (is_clicked(KEY_SPACE)) {
        this.currentScene = (this.currentScene + 1) % this.scenes.length;
    }
    if (is_clicked(KEY_ESCAPE)) {
        exit();
    }
};

var sceneManager = new SceneManager();

function onRender() {
    sceneManager.onRender();
}

function onCreate() {
    print("onCreate");
}

function onDispose() {
    print("onDispose");
}
