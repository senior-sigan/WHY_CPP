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
	cd cmake-build-debug;cmake ..

compile:
	cd cmake-build-debug/example;make -j4

run:
	cd cmake-build-debug/example;./example

doxygen:
	rm -rf docs
	doxygen Doxyfile

whycpp-js-compile:
	cd cmake-build-debug/whycpp_js;make -j4

whycpp-js-run:
	cd cmake-build-debug/whycpp_js/src/example;../whycpp_js