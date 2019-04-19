var Prisma = require('prisma');
var PaletteScene = require('palette');
var RandomLinesScene = require('random_lines');
var ButtonsScene = require('buttons');
var MouseScene = require('mouse');
var SceneManager = require('scene_manager');

var CONFIG = {
    'width': 256,
    'height': 144,
    'name': 'JS Application',
    'is_fullscreen': false,
    'window_size_multiplier': 3,
    'ms_per_frame': 16
};

var sceneManager = new SceneManager([
    new PaletteScene(),
    new RandomLinesScene(),
    new ButtonsScene(),
    new MouseScene(),
    new Prisma()
]);

function onRender() {
    sceneManager.onRender();
}

function onCreate() {
    print("onCreate");
}

function onDispose() {
    print("onDispose");
}
