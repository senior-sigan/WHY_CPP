reload-web:
	rm -rf cmake-build-debug
	mkdir cmake-build-debug
	cd cmake-build-debug;emcmake cmake ..

reload:
	rm -rf cmake-build-debug
	mkdir cmake-build-debug
	cd cmake-build-debug;cmake ..

serve:
	cd cmake-build-debug/example;python -m http.server

compile:
	cd cmake-build-debug/example;make -j4