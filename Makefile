ifeq ($(OS),Windows_NT)
	FLAGS = -DCMAKE_SH="CMAKE_SH-NOTFOUND" -G "CodeBlocks - MinGW Makefiles" -DUSE_C=ON -DUSE_JS=ON
else
	FLAGS = -DUSE_C=ON -DUSE_JS=ON
endif


desktop: reload example-compile example-run

web: reload-web compile-web serve

desktop-js: reload example-js-compile example-js-run

desktop-c: reload example-c-compile example-c-run

reload-web:
	rm -rf cmake-build-debug-web
	mkdir cmake-build-debug-web
	cd cmake-build-debug-web;emcmake cmake ..

compile-web:
	cd cmake-build-debug-web/example;$(MAKE) -j4

serve:
	cd cmake-build-debug-web/example;emrun index.html

clean:
	rm -rf cmake-build-debug

mkdir_build:
	[ -d ./cmake-build-debug ] | mkdir -p cmake-build-debug

reload: mkdir_build
	cd cmake-build-debug;cmake .. $(FLAGS)

example-compile:
	cd cmake-build-debug;cmake --build . --target example -j4

example-run:
	cd cmake-build-debug/example;./example

doxygen:
	rm -rf docs
	doxygen Doxyfile

example-js-compile:
	cd cmake-build-debug;cmake --build . --target example_js -j4

example-js-run:
	cd cmake-build-debug/example_js/;./example_js

example-c-compile:
	cd cmake-build-debug;cmake --build . --target example_c -j4

example-c-run:
	cd cmake-build-debug/example_c/;./example_c