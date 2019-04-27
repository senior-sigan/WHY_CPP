function NativeHelloWorld() {
}

NativeHelloWorld.prototype.onRender = function () {
    native_hello_world();
};
NativeHelloWorld.prototype.onCreate = function () {};
NativeHelloWorld.prototype.onDispose = function () {};

module.exports = NativeHelloWorld;