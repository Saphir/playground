#define PY_SSIZE_T_CLEAN
#include <Python.h>
#include <cstdio>

static PyObject *demo_c_func(PyObject *self, PyObject *args, PyObject *kwargs) {
  char position_arg[] = "";
  char kw_data[] = "data";
  char kw_obj[] = "obj";
  char *kwlist[] = {position_arg, position_arg, position_arg,
                    kw_data,      kw_obj,       nullptr};

  char demo_char = '\0';
  int demo_int = 0;
  char *demo_s = nullptr;
  char *demo_buf = nullptr;
  Py_ssize_t demo_buf_len = 0;
  PyObject *demo_obj = nullptr;

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "cis|$z#O:demo_c_func", kwlist,
                                   &demo_char,     // position only arg
                                   &demo_int,      // position only arg
                                   &demo_s,        // position only arg
                                   &demo_buf,      // key word data arg buffer
                                   &demo_buf_len,  // key word data arg len
                                   &demo_obj       // key word obj arg
                                   )) {
    return nullptr;
  }

  printf("[%s] %c %d %s\n", __FUNCTION__, demo_char, demo_int, demo_s);
  printf("[%s] demo_obj %p\n", __FUNCTION__, demo_obj);
  printf("%s", "[C] ");
  PyObject_Print(demo_obj, stdout, Py_PRINT_RAW);
  printf("\n");

  auto get_attr_demo_bytes = PyObject_GetAttrString(demo_obj, "demo_bytes");
  if (get_attr_demo_bytes == nullptr) {
    return nullptr;
  }
  auto is_bytes = PyBytes_Check(get_attr_demo_bytes);
  if (is_bytes) {
    char *demo_bytes_data;
    Py_ssize_t demo_bytes_len;
    PyBytes_AsStringAndSize(get_attr_demo_bytes, &demo_bytes_data,
                            &demo_bytes_len);
    printf("[%s] demo_obj.demo_bytes[%lu] ", __FUNCTION__, demo_bytes_len);
    for (Py_ssize_t i = 0; i < demo_bytes_len; i++) {
      printf("0x%02x ", demo_bytes_data[i]);
    }
    printf("\n");
  }

  return Py_None;
}

static PyMethodDef demo_ext_funcs[] = {
    {"demo_c_func",  // the name to invoke this particular function
     reinterpret_cast<PyCFunction>(demo_c_func),  // the C function to call
     METH_VARARGS | METH_KEYWORDS,  // a flag indicating the function needs two
                                    // arguments of
                                    // type PyObject*: self, args
     "C demo function"},
    {nullptr, nullptr, 0, nullptr}};

static struct PyModuleDef demo_ext = {
    PyModuleDef_HEAD_INIT,  // a member of type PyModuleDef_Base, which is
                            // advised to have just this one value
    "demo_ext",             // the name of your Python C extension module
    "Python C API: demo extension",  // module docstring
    -1,             // the amount of memory needed to store your program state
    demo_ext_funcs  // the reference to your method table defined earlier
};

PyMODINIT_FUNC PyInit_demo_ext() { return PyModule_Create(&demo_ext); }
