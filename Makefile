default: build

.PHONY: build clean
build:
	@mkdir -p build && cd build && cmake .. && make

demo: build
	cd build/src && PYTHONPATH=$(shell pwd)/build/src/ctypes_protobuf_pyobject python ../../src/ctypes_protobuf_pyobject/demo.py

clean:
	@rm -rf build
