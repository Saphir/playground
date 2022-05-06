BUILD_DIR := ./build
MAIN := main

.PHONY: build clean
build:
	[ ! -d build ] || rm -rf build && mkdir build && cd build && \
	cmake .. && make

clean:
	rm -rf $(BUILD_DIR)

	@mkdir -p build && cd build && cmake .. && make

clean:
	@rm -rf build
