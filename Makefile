desktop: reload compile run

web: reload-web compile-web serve

desktop-js: reload whycpp-js-compile whycpp-js-run

reload-web:
	rm -rf cmake-build-debug-web
	mkdir cmake-build-debug-web
	cd cmake-build-debug-web;emcmake cmake ..

compile-web:
	cd cmake-build-debug-web/example;make -j4

serve:
	cd cmake-build-debug-web/example;emrun index.html

reload:
	rm -rf cmake-build-debug
	mkdir cmake-build-debug
	cd cmake-build-debug;cmake .. -DUSE_PYTHON=ON -DUSE_JS=ON

compile:
	cd cmake-build-debug/example;make -j4

run:
	cd cmake-build-debug/example;./example

doxygen:
	rm -rf docs
	doxygen Doxyfile

example-js-compile:
	cd cmake-build-debug/example_js;make -j4

example-js-run:
	cd cmake-build-debug/example_js/;./example_js