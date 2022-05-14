default: all

all: build run

.PHONY: build clean
build:
	mkdir -p build && cd build && cmake .. && make

run: build
	python addressbook.py

clean:
	rm -rf build
