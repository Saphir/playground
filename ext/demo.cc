#define PY_SSIZE_T_CLEAN
#include <Python.h>
#include <cstdio>

static PyObject *demo_c_func(PyObject *self, PyObject *args) {
  char demo_char = '\0';
  int demo_int = 0;
  const char *demo_s = nullptr;
  const char *demo_buf = nullptr;
  Py_ssize_t demo_buf_len = 0;

  if (!PyArg_ParseTuple(args, "cisz#:demo_c_func", &demo_char, &demo_int,
                        &demo_s, &demo_buf, &demo_buf_len)) {
    return nullptr;
  }

  printf("[%s] %c %d %s\n", __FUNCTION__, demo_char, demo_int, demo_s);
  printf("[%s] demo_buf[%u] ", __FUNCTION__, demo_buf_len);
  for (Py_ssize_t i = 0; i < demo_buf_len; i++) {
    printf("0x%02x ", demo_buf[i]);
  }
  printf("\n");

  return Py_None;
}

static PyMethodDef demo_ext_funcs[] = {
    {"demo_c_func",  // the name to invoke this particular function
     demo_c_func,    // the name of the C function to invoke
     METH_VARARGS,   // a flag indicating the function needs two arguments of
                     // type PyObject*: self, args
     "C demo function"},
    {NULL, NULL, 0, NULL}};

static struct PyModuleDef demo_ext = {
    PyModuleDef_HEAD_INIT,  // a member of type PyModuleDef_Base, which is
                            // advised to have just this one value
    "demo_ext",             // the name of your Python C extension module
    "Python C API: demo extension",  // module docstring
    -1,             // the amount of memory needed to store your program state
    demo_ext_funcs  // the reference to your method table defined earlier
};

PyMODINIT_FUNC PyInit_demo_ext() { return PyModule_Create(&demo_ext); }
