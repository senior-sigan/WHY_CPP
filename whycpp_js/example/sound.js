function SoundScene() {
}

SoundScene.prototype.onRender = function () {
    if (is_clicked(KEY_S)) {
        playSFX("bonus",1);
    }
};
SoundScene.prototype.onCreate = function () {
    draw_clear_screen(PALETTE[0]);
    show_text("Press S\nto hear sound\nPress Space to exit", 1, 10, PALETTE[3], 2, 1);
    importSFX("assets/bonus.wav", "bonus");
};
SoundScene.prototype.onDispose = function () {};

module.exports = SoundScene;