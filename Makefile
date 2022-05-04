BUILD_DIR := ./build
MAIN := main

run: run_c run_py

run_c: ${BUILD_DIR}/${MAIN}
	${BUILD_DIR}/${MAIN}

run_py: ${BUILD_DIR}/src/libtest.so
	poetry run python3 test_ctypes.py

${BUILD_DIR}/${MAIN}: build
${BUILD_DIR}/src/libtest.so: build

.PHONY: build clean
build:
	[ ! -d build ] || rm -rf build && mkdir build && cd build && cmake .. && make

clean:
	rm -rf $(BUILD_DIR)

