default: build

.PHONY: build clean
build:
	python setup.py install

demo: build
	python -c 'import fputs; print(fputs.__doc__)'

clean:
	@rm -rf build
