BUILD_DIR := ./build

.PHONY: build clean
build:
	[ ! -d build ] || rm -rf build && mkdir build && cd build && cmake .. && make

clean:
	rm -rf $(BUILD_DIR)

