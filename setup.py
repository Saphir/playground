from distutils import extension
from setuptools import setup

demo_ext = extension.Extension(
  name = 'demo_ext',
  sources = ['./ext/demo.cc'],
  extra_compile_args=['-std=c++11', '-O0', '-g'],
)

setup(name = "python_c_api",
      version = "0.0.1",
      description = "Python C API demo",
      author = "Elan",
      author_email = "elan.zheng@momenta.ai",
      packages = ["python_c_api"],
      install_requires=[
        'glog',
      ],
      ext_modules = [
        demo_ext,
      ]
)