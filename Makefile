
build:
	cmake --build build
.PHONY: build

run: build
	./build/main
.PHONY: run
