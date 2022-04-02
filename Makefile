default: build

.PHONY: build
build:
	@[ -d build ] || [ ! -e build ] || rm -rf build && mkdir -p build && cd build && cmake .. && make
