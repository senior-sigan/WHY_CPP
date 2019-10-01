ifeq ($(OS),Windows_NT)
	FLAGS = -DCMAKE_SH="CMAKE_SH-NOTFOUND" -G "CodeBlocks - MinGW Makefiles" -DUSE_C=ON -DUSE_JS=ON
else
	FLAGS = -DUSE_C=ON -DUSE_JS=ON
endif


desktop: reload compile run

web: reload-web compile-web serve

desktop-js: reload whycpp-js-compile whycpp-js-run

reload-web:
	rm -rf cmake-build-debug-web
	mkdir cmake-build-debug-web
	cd cmake-build-debug-web;emcmake cmake ..

compile-web:
	cd cmake-build-debug-web/example;$(MAKE) -j4

serve:
	cd cmake-build-debug-web/example;emrun index.html

reload:
	rm -rf cmake-build-debug
	mkdir cmake-build-debug
	cd cmake-build-debug;cmake .. $(FLAGS)

compile:
	cd cmake-build-debug/example;$(MAKE) -j4

run:
	cd cmake-build-debug/example;./example

doxygen:
	rm -rf docs
	doxygen Doxyfile

example-js-compile:
	cd cmake-build-debug/example_js;$(MAKE) -j4

example-js-run:
	cd cmake-build-debug/example_js/;./example_js