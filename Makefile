default: demo

.PHONY: demo build
build: python_c_api/demo.py ext/demo.cc setup.py
	poetry run python setup.py install

demo:
	poetry run python python_c_api/demo.py
